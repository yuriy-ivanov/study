#ifndef GUARD_functions
#define GUARD_functions

//functions.h

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	double final_grade;
};

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info& s);
// Task 8.3. - Change function param from value to reference.
// Already done before chapter 8.
template <class T> T median(std::vector<T>& vec)
{
	typedef typename std::vector<T>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0) throw domain_error("Empty vector mediate");

	// cannot use "T median(const vector<T>& vec)" due to "sort" call:
	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid+1]) / 2 : vec[mid];
};
// Task 10.2. - Reimplemet median() function to support vectors and arrays
// of any arithmetic types.
// Task 10.3. - Call of median() function should not change order of items in vector/array.
template <typename Input> typename std::iterator_traits<Input>::value_type median2(const Input begin, const Input end)
{
	if (end <= begin) throw domain_error("Incorrect/empty array/vector mediate");
	size_t size = end - begin;

	typedef typename std::iterator_traits<Input>::value_type RetType;
	
	std::vector<RetType> temp(begin, end);
	sort(temp.begin(), temp.end());

	size_t mid = size / 2;
	
	return size % 2 == 0 ? (temp[mid] + temp[mid+1]) / 2 : temp[mid];
};
double average(const std::vector<double>&);
template <class T> bool compare(const T& x, const T& y)
{
	return x.name() < y.name();
}
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& cread(std::istream&, std::vector<std::string>&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
std::vector<std::string> split(const std::string&);
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> hcat_v2(const std::vector<std::string>&, const std::vector<std::string>&);
void output(std::ostream& os, const std::vector<std::string>&);
std::string randomStrGen(int);
std::vector<Student_info> studentGen(int);
bool is_palindrome(const std::string&);
bool has_asc_desc(const std::string&);
bool not_url_char(char c);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);
bool did_all_hw(const Student_info&);
double grade_aux(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&, double analysis(const std::vector<Student_info>&), const std::vector<Student_info>&, const std::vector<Student_info>&);
double average_grade(const Student_info&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median(const Student_info&);
double optimistic_median_analysis (const std::vector<Student_info>&);
double common_analysis(const std::vector<Student_info>&, double func(const Student_info&));
void common_write_analysis(std::ostream&, const std::string&, double func(const Student_info&), const std::vector<Student_info>&, const std::vector<Student_info>&);
// Task 8.1. - Write template function parametrized by final grade function type
// Dependency mods
template<class T> void common_write_analysis_g(std::ostream& out, const std::string& name, T func, const std::vector<Student_info>& did, const std::vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis_g(did, func) <<
		", median(didnt) = " << analysis_g(didnt, func) << std::endl;
};
// Task 8.1. - Write template function parametrized by final grade function type
template<class T> double analysis_g(const std::vector<Student_info>& students, T func)
{
	std::vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), func);

	return median(grades);
};
void read_and_separate(std::vector<Student_info>&, std::vector<Student_info>&);
std::map<std::string, std::vector<size_t> > xref(std::istream& in, std::vector<std::string> find_words(const std::string&) = split);
Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
std::list<std::string> gen_sentence_list(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
void gen_aux_list(const Grammar&, const std::string&, std::list<std::string>&);
int nrand(int);
template<class Out> void gen_sentence_iterator(const Grammar& g, Out& os)
{
	gen_aux_iterator(g, "<sentence>", os);
};
template<class Out> void gen_aux_iterator(const Grammar& g, const std::string& word, Out& os)
{
	if (!bracketed(word))
	{
		*os++ = word;
	} else {
		Grammar::const_iterator it = g.find(word);
		if (it == g.end()) throw logic_error("empty rule");

		const Rule_collection& c = it->second;
		const Rule& r = c[nrand(c.size())];

		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) gen_aux_iterator(g, *i, os);
	}
};

#endif
