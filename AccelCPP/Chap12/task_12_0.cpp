// Task 12.0. - Source from book.
// Task 12.2. - Implement 'c_str()', 'data()' and 'copy' functions.
// Task 12.3. - Implement relation operators for Str class ('<' and '>').
// Task 12.4. - Implement equal operators for Str class ('==' and '!=').
// Task 12.5. - Implement concatenation of Str objects avoiding 'const char*' cast.
// Task 12.6. - Implement function to implicitly use 'Str' object as a condition.
//				'False' - when Str object is an empty string. And vice versa - 'True'.
// Task 12.7. - Add random access iterators and iterator operations 'begin()' and 'end()'.
// Task 12.8. - Implement 'getline()' function.
// Task 12.9. - Use class 'ostream_iterator' to modify output operator of 'Str' class.
// Task 12.10. - Str has defined a constructor that takes a pair of iterators, we can imagine that
//				 such a constructor would be useful in class Vec. Add this constructor to Vec, 
// 				 and reimplement Str to use the Vec constructor instead of calling copy.
// Task 12.12. - Define the 'insert' function that takes two iterators for the 'Vec' and 'Str' classes.
// Task 12.13. - Provide an 'assign' function that could be used to assign the values in an array to a 'Vec'.

#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstring>
#include "Vec.h"

class Str {
friend std::istream& operator>>(std::istream&, Str&);

public:
	typedef Vec<char>::size_type size_type;
	typedef Vec<char>::const_iterator const_iterator;
	typedef Vec<char>::iterator iterator;

	Str() { init_ptrs(); }
	Str(size_type n, char c):m_data(n, c) { init_ptrs(); }
	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(m_data));
		init_ptrs();
	}

	template<class In> Str(In i, In j):m_data(i, j) {
		//std::copy(i, j, std::back_inserter(data));
		init_ptrs();
	}

	char& operator[](size_type i) { return m_data[i]; }
	const char& operator[](size_type i) const { return m_data[i]; }
	Str& operator+=(const Str& s) {
		std::copy(s.m_data.begin(), s.m_data.end(), std::back_inserter(m_data));
		return *this;
	}
	operator bool() const {	return (m_data.size() > 0); }

	size_type size() const { return m_data.size(); }

	void copy(char* p, size_type n) {
		for (size_type i = 0; i != n; ++i) *(p+i) = m_data[i];
	}
	const char* data() const {
		if(!dataPtr) delete dataPtr;
		dataPtr = new char[m_data.size()];
		std::copy(m_data.begin(), m_data.end(), dataPtr);
		return dataPtr;
	}
	const char* c_str() const {
		if (!nTermPtr) delete nTermPtr;
		nTermPtr = new char[m_data.size()];
		std::copy(m_data.begin(), m_data.end(), nTermPtr);
		nTermPtr[m_data.size()] = '\0';
		return nTermPtr;
	}
	const_iterator begin() const {
		return m_data.begin();
	}
	const_iterator end() const {
		return m_data.end();
	}
	void getline(std::istream& is) {
		m_data.clear();
		char c;
		while (is.get(c) && !iscntrl(c))
			if (is) m_data.push_back(c);
	}
	template<class It> void insert(It i, It j) {
		m_data.insert(i, j);
	}
	template<class It> void assign(It i, It j) {
		m_data.assign(i, j);
	}

private:
	Vec<char> m_data;
	mutable char* nTermPtr;
	mutable char* dataPtr;

	void init_ptrs() { nTermPtr = dataPtr = NULL; }
};

std::ostream& operator<<(std::ostream& os, const Str& s) {
	//Commented due to Task 12.9. - Use class 'ostream_iterator' to modify output operator of 'Str' class.
	/*for (Str::size_type i = 0; i != s.size(); ++i)
		os << s[i];
	return os;*/
	ostream_iterator<char> out(os);
	copy(s.begin(), s.end(), out);
	return os;
}
std::istream& operator>>(std::istream& is, Str& s) {
	s.m_data.clear();
	char c;
	while (is.get(c) && isspace(c)) ;
	if (is) {
		do s.m_data.push_back(c);
		while (is.get(c) && !isspace(c));

		if(is) is.unget();
	}
	return is;
}
Str operator+(const Str& s, const Str& t) {
	Str r = s;
	r += t;
	return r;
}
Str operator+(const Str& s, const char* t) {
	Str r = s;
	r += t;
	return r;
}
bool operator>(const Str& lhs, const Str& rhs) {
	return (strcmp(lhs.c_str(), rhs.c_str()) > 0);
}
bool operator<(const Str& lhs, const Str& rhs) {
	if (strcmp(lhs.c_str(), rhs.c_str()) < 0) return true;
	return false;
}
bool operator==(const Str& lhs, const Str& rhs) {
	return (strcmp(lhs.c_str(), rhs.c_str()) == 0);
}
bool operator!=(const Str& lhs, const Str& rhs) {
	return !(lhs == rhs);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Str s1("Hello ");
	Str s2 = "world ";
	Str s3 = s1 + s2 + "!";
	cout << s3 << endl;
	cout << s3.c_str() << endl;
	
	const char* d = s3.data();
	for (Str::size_type i = 0; i != s3.size(); ++i) cout << d[i]; cout << endl;
	
	char* p = new char[10];
	size_t count = 4; // Number of chars to copy
	s3.copy(p, count);
	for (Str::size_type i = 0; i != count; ++i) cout << p[i]; cout << endl;

	for (Str::const_iterator i = s3.begin(); i != s3.end(); ++i) cout << *i; cout << endl;

	Str s4;
	s4.getline(cin);
	cout << "You entered: " << s4 << endl;

	Str s5("base ");
	s5.insert(s4.begin(), s4.end());
	cout << "Insert result: " << s5 << endl;

	s5 = "Before 'assign'";
	cout << s5 << endl;
	s5.assign(s4.begin(), s4.end());
	cout << "After 'assign': " << s5 << endl;
	
	
	delete p;
	delete d;
	return 0;
}

