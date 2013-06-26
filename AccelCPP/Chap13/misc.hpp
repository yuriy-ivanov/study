#ifndef MISC_HPP_
#define MISC_HPP_

#include "../functions.h"

namespace misc {


class Core {
	friend class Student_info;
public:
	Core(): midterm(0), final(0) {
		std::cerr << "Core::Core()" << std::endl; //Task 13.1.
	}
	Core(std::istream& is) {
		std::cerr << "Core::Core(std::istream&)" << std::endl; //Task 13.1.
		read(is);
	}
	virtual ~Core() { }

	std::string name() const;

	virtual std::istream& read(std::istream&);
	virtual double grade() const;
	virtual bool valid() const { return !homework.empty(); } //Task 13.3.

protected:
	virtual Core* clone() const { return new Core(*this); }
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;

private:
	std::string n;
};

class Grad: public Core {
public:
	Grad(): thesis(0) {
		std::cerr << "Grad::Grad()" << std::endl; //Task 13.1.
	}
	Grad(std::istream& is) {
		std::cerr << "Grad::Grad(std::istream&)" << std::endl; //Task 13.1.
		read(is);
	}

	double grade() const;
	std::istream& read(std::istream&);
	bool valid() const { return !homework.empty() && thesis > 0.0; }

protected:
	Grad* clone() const { return new Grad(*this); }

private:
	double thesis;
};

class Zachot: public Core { //Task 13.6.
public:
	Zachot() {
		std::cerr << "Zachot::Zachot()" << std::endl; //Task 13.1.
	}
	Zachot(std::istream& is) {
		std::cerr << "Zachot::Zachot(std::istream&)" << std::endl; //Task 13.1.
		read(is);
	}

	double grade() const;
	std::istream& read(std::istream&);
	bool valid() const { return grade() >= 60.0; }

protected:
	Zachot* clone() const { return new Zachot(*this); }
};

class Tested: public Core { //Task 13.7.
public:
	Tested() {
		std::cerr << "Tested::Tested()" << std::endl; //Task 13.1.
	}
	Tested(std::istream& is) {
		std::cerr << "Tested::Tested(std::istream&)" << std::endl; //Task 13.1.
		read(is);
	}

	double grade() const;
	std::istream& read(std::istream&);
	bool valid() const { return !tests.empty(); }

protected:
	Tested* clone() const { return new Tested(*this); }

private:
	std::vector<double> tests;
};

class Student_info {
public:
	Student_info(): cp(0) { }
	Student_info(std::istream& is): cp(0) { read(is); }
	Student_info(const Student_info&);
	Student_info& operator=(const Student_info&);
	~Student_info() { delete cp; }

	std::istream& read(std::istream&);

	std::string name() const {
		if (cp) return cp->name();
		else throw std::runtime_error("Uninitialized Student data");
	}

	double grade() const {
		if (cp) return cp->grade();
		else throw std::runtime_error("Uninitialized Student data");
	}

	static bool compare(const Student_info& s1, const Student_info& s2) {
		return s1.name() < s2.name();
	}

	static bool valid(const Student_info& src) { //Task 13.5.
		if (src.cp) return src.cp->valid();
		return false;
	}

	char get_alpha_mark() const;

private:
	Core* cp;
};

std::string Core::name() const { return n; }

double Core::grade() const {
	return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in) {
	in >> n >> midterm >> final;
	return in;
}

std::istream& Core::read(std::istream& in) {
	read_common(in);
	read_hw(in, homework);
	return in;
}

char Student_info::get_alpha_mark() const { //Task 13.4.
	static const char letters[] = { 'A', 'B', 'C', 'D', 'F' };
	static const double marks[] = { 90.0, 80.0, 70.0, 60.0, 0.0 };

	if (cp)
		for (size_t i = 0; i < (sizeof(marks)/sizeof(*marks)); ++i)
		{
			if (cp->grade() > marks[i]) return letters[i];
		}
	return '?';
}

std::istream& Grad::read(std::istream& in) {
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const {
	return std::min(Core::grade(), thesis);
}

std::istream& Zachot::read(std::istream& in) {
	read_common(in);
	read_hw(in, homework);
	return in;
}

double Zachot::grade() const {
	if (homework.empty()) return (midterm + final) / 2;
	return ::grade(midterm, final, homework);
}

std::istream& Tested::read(std::istream& in) {
	read_common(in);
	read_hw(in, tests);
	return in;
}

double Tested::grade() const {
	if (tests.empty()) return (midterm + final) / 2;
	return ::grade(midterm, final, tests);
}

std::istream& Student_info::read(std::istream& is) {
	delete cp;

	char ch;
	is >> ch;

	if (ch == 'U') cp = new Core(is);
	if (ch == 'Z') cp = new Zachot(is);
	if (ch == 'T') cp = new Tested(is);
	else cp = new Grad(is);

	return is;
}

Student_info::Student_info(const Student_info& s): cp(0) {
	if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator =(const Student_info& s) {
	if (&s != this) {
		delete cp;
		if (s.cp) cp = s.cp->clone();
		else cp = 0;
	}
	return *this;
}

}
#endif /* MISC_HPP_ */
