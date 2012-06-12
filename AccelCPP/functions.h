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
double median(const std::vector<double>&);
double average(const std::vector<double>&);
bool compare(const Student_info&, const Student_info&);
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
void read_and_separate(std::vector<Student_info>&, std::vector<Student_info>&);
std::map<std::string, std::vector<size_t> > xref(std::istream& in, std::vector<std::string> find_words(const std::string&) = split);
Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
std::list<std::string> gen_sentence_list(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
void gen_aux_list(const Grammar&, const std::string&, std::list<std::string>&);
int nrand(int);

#endif
