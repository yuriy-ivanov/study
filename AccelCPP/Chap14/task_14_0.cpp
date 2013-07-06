// Task 14.0. - Source from book.
// Task 14.1. - Implement compare operation for objects type of Ptr<Core>.
// Task 14.2. - Implement app for calculate final grade mark of Ptr<Core> objects.
// Task 14.3. - Implement class Student_info to use class Ptr.


#include <iomanip>
#include "../functions.h"
#include "../Chap13/misc.hpp"

template<class T> T* clone(const T* tp) { return tp->clone(); }

template<class T> class Ptr {
public:
	Ptr(): refptr(new std::size_t(1)), p(0) { }
	Ptr(T* t): refptr(new std::size_t(1)), p(t) { }
	Ptr(const Ptr& h): refptr(h.refptr), p(h.p) { ++*refptr; }
	~Ptr() {
		if (--*refptr == 0) {
			delete refptr;
			delete p;
		}
	}

	Ptr& operator=(const Ptr&);
	operator bool() const { return p; }
	T& operator*() const { if(p) return *p; }
	T* operator->() const { if(p) return p; }

	void make_unique() {
		if (*refptr != 1) {
			--*refptr;
			refptr = new size_t(1);
			p = p? clone(p): 0;
		}
	}

private:
	T* p;
	std::size_t* refptr;
};

template<class T>
Ptr<T>& Ptr<T>::operator =(const Ptr& rhs)
{
	++*rhs.refptr;
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}

	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

//Task 14.1.
bool compare_ptr_core(const Ptr<misc::Core>& lhs, const Ptr<misc::Core>& rhs)
{
	return lhs->name() < rhs->name();
}

int main() {

	//Task 14.2.
	std::vector<Ptr<misc::Core> > students;
		Ptr<misc::Core> record;

		std::string::size_type maxlen = 0;

		while (record->read(std::cin)) {
			maxlen = std::max(maxlen, record->name().size());
			students.push_back(record);
		}

		std::sort(students.begin(), students.end(), compare_ptr_core);

		for (std::vector<Student_info>::size_type i = 0;
				i != students.size(); ++i) {
			std::cout << students[i]->name()
					<< std::string(maxlen + 1 - students[i]->name().size(), ' ');

			try {
				double final_grade = students[i]->grade();
				std::streamsize prec = std::cout.precision();
				std::cout << std::setprecision(3) << final_grade
						<< std::setprecision(prec) << std::endl;
			} catch (std::domain_error& e) {
				std::cout << e.what() << std::endl;
			}
		}


}
