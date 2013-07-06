//Task 14.3. - Implement class Student_info_ptr to use class Ptr.

#include "task_14_0.cpp"

class Core {
	friend class Student_info_ptr;
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

class Student_info_ptr {
public:
	Student_info_ptr() { }
	Student_info_ptr(std::istream& is) { read(is); }
	Student_info_ptr(const Student_info_ptr&);
	Student_info_ptr& operator=(const Student_info_ptr&);
	~Student_info_ptr() { }

	std::istream& read(std::istream&);

	std::string name() const { return cp->name(); }

	double grade() const { return cp->grade(); }

	static bool compare(const Student_info_ptr& s1, const Student_info_ptr& s2) {
		return s1.name() < s2.name();
	}

	static bool valid(const Student_info_ptr& src) { //Task 13.5.
		return src.cp->valid();
	}

	char get_alpha_mark() const;

private:
	Ptr<Core> cp;
};

char Student_info_ptr::get_alpha_mark() const { //Task 13.4.
	static const char letters[] = { 'A', 'B', 'C', 'D', 'F' };
	static const double marks[] = { 90.0, 80.0, 70.0, 60.0, 0.0 };

	if (cp)
		for (size_t i = 0; i < (sizeof(marks)/sizeof(*marks)); ++i)
		{
			if (cp->grade() > marks[i]) return letters[i];
		}
	return '?';
}

Student_info_ptr::Student_info_ptr(const Student_info_ptr& s) {
	cp = s.cp->clone();
}

Student_info_ptr& Student_info_ptr::operator =(const Student_info_ptr& s) {
	if (&s != this) {
		cp = s.cp->clone();
	}
	return *this;
}

std::istream& Student_info_ptr::read(std::istream& is) {

	char ch;
	is >> ch;

	if (ch == 'U') cp->read(is);
	//if (ch == 'Z') cp = new Zachot(is);
	//if (ch == 'T') cp = new Tested(is);
	else cp->read(is); //Grad(is);

	return is;
}
