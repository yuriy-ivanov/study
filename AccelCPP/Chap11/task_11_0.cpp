// 
//
// Task 11.0. Original src from book.
// Task 11.6. Add an operation to remove an element from a 'Vec' and another to empty the entire 'Vec'. 
//			  These should behave analogously to the 'erase' and 'clear' operations on vectors.

#include <memory>
#include <stdexcept>

using namespace std;

template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() { create(); }
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator=(const Vec& v) {
		if (&v != this) {
			uncreate();
			create(v.begin(), v.end());
		}
		return *this;
	}
	~Vec() { uncreate(); }

	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	void push_back(const T& t) {
		if (avail == limit) grow();
		unchecked_append(t);
	}

	void clear() { uncreate(); }
	
	iterator erase(const_iterator position) {
		if (position >= avail) throw domain_error("vector erase iterator outside range");
		if (position == data) { //erase first element
			alloc.destroy(data++);
			alloc.deallocate(position);
			return data;
		}
		if (position == avail - 1) { //erase last element
			alloc.destroy(avail--);
			alloc.deallocate(position);
			return avail;
		}

		// erase element between first and last
		alloc.destroy(position);
		size_t size = limit - data;
		iterator new_data = alloc.allocate(size);
		iterator part2 = uninitialized_copy(data, position, new_data);
		iterator new_avail = uninitialized_copy(++position, avail, ++part2);
		alloc.deallocate(data, size);
		data = new_data;
		avail = new_avail;
		limit = data + size;
		return part2;
	}

	iterator erase(const_iterator first, const_iterator last) {
		if (first < data || last >= avail) throw domain_error("vector erase iterator outside range");
		if (first == data && last == avail - 1) { uncreate(); return avail; }
		
		iterator it = last;
		while (it != first) alloc.destroy(--it);

		size_t size = limit - data - (last - first);
		iterator new_data = alloc.allocate(size);
		iterator part2 = uninitialized_copy(data, first, new_data);
		iterator new_avail = uninitialized_copy(last + 1, avail, ++part2);
		alloc.deallocate(data, limit - data);
		data = new_data;
		avail = new_avail;
		limit = data + size;
		return part2;

	}

	size_type size() const { return avail - data; }
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

private:
	iterator data;
	iterator avail;
	iterator limit;

	allocator<T> alloc;
	
	void create() {	data = avail = limit = 0; }
	void create(size_type n, const T& val) {
		data = alloc.allocate(n);
		limit = avail = data + n;
		uninitialized_fill(data, limit, val);
	}
	void create(const_iterator i, const_iterator j) {
		data = alloc.allocate(j - i);
		limit = avail = uninitialized_copy(i, j, data);
	}
	void uncreate() {
		if(data) {
			iterator it = avail;
			while (it != data) alloc.destroy(--it);
			alloc.deallocate(data, limit - data);
		}
		data = limit = avail = 0;
	}
	void grow() {
		size_type new_size = max(2* (limit - data), ptrdiff_t(1));
		iterator new_data = alloc.allocate(new_size);
		iterator new_avail = uninitialized_copy(data, avail, new_data);
		uncreate();
		data = new_data;
		avail = new_avail;
		limit = data + new_size;
	}
	void unchecked_append(const T& val) { alloc.construct(avail++, val); }
};

int main()
{
	Vec<int> v;
	v.push_back(100);
	v.size();
	
	return 0;
}

