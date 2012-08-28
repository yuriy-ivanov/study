#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <functional>
#include <iterator>
#include <assert.h>
#include <map>
#include "functions.h"

using namespace std;

double average(const vector<double>& vec)
{
	if (vec.size() == 0) throw domain_error("Empty vector");
	double summ = 0.0;
	for (vector<double>::size_type i = 0; i < vec.size(); ++i) summ += vec[i];
	return summ / (double)vec.size();
}
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;

	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty()) return grade(s.midterm, s.final, 0);
	else return grade(s.midterm, s.final, median(nonzero));
}
// Task 6.5. - Write analysis func that calls "optimistic_median" func
double optimistic_median_analysis (const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

	return median(grades);
}
// Task 6.6. - Write single analysis func (for median, optimistic_median and average)
double common_analysis(const vector<Student_info>& students, double func(const Student_info&))
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), func);

	return median(grades);
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0) throw domain_error("Student did not complete any of homework");
	return grade(midterm, final, average(hw));
}
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}
bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}
double grade_aux(const Student_info& s)
{
	try { return grade(s); }
	catch (domain_error) { return grade(s.midterm, s.final, 0); }
}
double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

	return median(grades);
}
double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), average_grade);

	return median(grades);
}
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
istream& read(istream& is, Student_info& s)
{
	double midterm, final;
	is >> s.name >> midterm >> final;

	vector<double> homework;
	read_hw(is, homework);

	//try { s.final_grade = grade(midterm, final, homework); }
	//catch (domain_error e) { cout << e.what(); }

	s.final_grade = grade(midterm, final, homework);

	return is;
}
istream& read_hw(istream& is, vector<double>& hw)
{
	if (is) {
		hw.clear();

		double x;

		while (is >> x) hw.push_back(x);

		is.clear();
	}
	return is;
}
istream& cread(istream& is, std::vector<string>& vec)
{
	if (is)
	{
		vec.clear();
		string s;
		while (is >> s) vec.push_back(s);
		is.clear();
	}
	return is;
}
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	while(iter != students.end()){
		if (fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			++iter;
	}
	return fail;
}
list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while(iter != students.end()){
		if (fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			++iter;
	}
	return fail;
}
// Task 6.7. - Func to read and separate students by whether all homework done or not.
void read_and_separate(vector<Student_info>& did, vector<Student_info>& didnt)
{
	Student_info student;

	while (read(cin, student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else 
			didnt.push_back(student);
	}

	if (did.empty()) {
		cout << "No one student did complete any of homework!" << endl;
	}

	if (didnt.empty()) {
		cout << "All of students did homework!" << endl;
	}
}
bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}
vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()){
		while (i != s.size() && isspace(s[i]))
		++i;

		string_size j = i;

		while (j != s.size() && !isspace(s[j]))
		++j;

		if (i != j){
			ret.push_back(s.substr(i, j - i));
			i = j;
		}

	}
	return ret;
}
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i < v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}
// Task 6.1. - update func for iterators use.
vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    //for (vector<string>::size_type i = 0; i < v.size(); ++i) {
	//	ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");}

	for (vector<string>::const_iterator it = v.begin(); it < v.end(); ++it) {
		ret.push_back("* " + (*it) + string(maxlen - (*it).size(), ' ') + " *");}
	
    ret.push_back(border);
    return ret;
}
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	vector<string> ret = top;
	
	for (vector<string>::const_iterator it = bottom.begin(); it < bottom.end(); ++it)
		ret.push_back(*it);

	return ret;
}
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	string::size_type width1 = width(left) + 1;
	vector<string>::size_type i = 0, j = 0;

	for(;i < max(left.size(), right.size()); ++i, ++j) {
		string s;
		if (i < left.size()) s = left[i];
		s += string(width1 - s.size(), ' ');
		if (j < right.size()) s += right[j];

		ret.push_back(s);
	}
	return ret;
}
// Task 6.1. - update func for iterators use.
vector<string> hcat_v2(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	string::size_type width1 = width(left) + 1;
	//vector<string>::size_type i = 0, j = 0;
	vector<string>::const_iterator i = left.begin(), j = right.begin();

	while (i < left.end() || j < right.end()) {
		string s;

		if (i < left.end()) s = *i++;

		s += string(width1 - s.size(), ' ');

		if (j < right.end()) s += *j++;

		ret.push_back(s);
	}
	return ret;
}
void output(ostream& os, const vector<string>& v)
{
	for (vector<string>::size_type i = 0; i < v.size(); ++i) os << v[i] << endl;
}
void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}
void common_write_analysis(ostream& out, const string& name, double func(const Student_info&), const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << common_analysis(did, func) <<
		", median(didnt) = " << common_analysis(didnt, func) << endl;
}

string randomStrGen(int length) {
    static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
    result.resize(length);

    //srand(time(NULL));
    for (int i = 0; i < length; i++) {
        assert(rand() % charset.length() < charset.length());
	result[i] = charset[rand() % charset.length()];
	}

    return result;
}
vector<Student_info> studentGen(int count)
{
	vector<Student_info> ret;
	while (count > 0){
		Student_info student;
	
		student.name = randomStrGen(20);
		student.midterm = rand() % 100;
		student.final = rand() % 100;
	
		int i = (rand() % 10) + 1; // "+1" to have at least one homework done.
		while (i > 0) {
			student.homework.push_back(rand() % 100);
			--i;
		}
		student.final_grade = grade(student);
		ret.push_back(student);
		--count;
	}
	return ret;
}
bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}
bool has_asc_desc(const string& s)
{
static const string asc_desc = "bdfhkltgjpqy";

for (string::const_iterator it = s.begin(); it != s.end(); ++it) {
	for (string::const_iterator iter = asc_desc.begin(); iter < asc_desc.end(); ++iter) {
		if (*it == *iter)
		return true;
		}
	}
return false;
}
bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";
	typedef string::const_iterator iter;
	iter i = b;

	while ((i = search(i, e, sep.begin(), sep.end())) != e) {
		if (i != b && i + sep.size() != e) {
			iter beg = i;

			while (beg != b && isalpha(beg[-1]))
				--beg;

			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}

		i += sep.size();
	}
	return e;
}
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}
vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while (b != e) {
		b = url_beg(b, e);

		if (b != e) {
			iter after = url_end(b, e);

			ret.push_back(string(b, after));
			b = after;
		}
	}
	return ret;
}
map<string, vector<size_t> > xref(istream& in, vector<string> find_words(const string&))
{
	string line;
	size_t line_number = 0;
	map<string, vector<size_t> > ret;

	while(getline(in, line))
	{
		++line_number;
		vector<string> words = find_words(line);

		for(vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);
	}
	return ret;
}
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	while(getline(in, line))
	{
		vector<string> entry = split(line);

		if(!entry.empty())
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}
vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}
//task 7.5. Modify program to use <list> instead of <vector>
list<string> gen_sentence_list(const Grammar& g)
{
	list<string> ret;
	gen_aux_list(g, "<sentence>", ret);
	return ret;
}
bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}
void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if (!bracketed(word))
	{
		ret.push_back(word);
	} else {
		Grammar::const_iterator it = g.find(word);
		if (it == g.end()) throw logic_error("empty rule");

		const Rule_collection& c = it->second;
		const Rule& r = c[nrand(c.size())];

		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) gen_aux(g, *i, ret);
	}
}
//task 7.5. Modify program to use <list> instead of <vector>
void gen_aux_list(const Grammar& g, const string& word, list<string>& ret)
{
	if (!bracketed(word))
	{
		ret.push_back(word);
	} else {
		Grammar::const_iterator it = g.find(word);
		if (it == g.end()) throw logic_error("empty rule");

		const Rule_collection& c = it->second;
		const Rule& r = c[nrand(c.size())];

		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) gen_aux_list(g, *i, ret);
	}
}
//task 7.9. Modify nrand() func to accept all range of int values.
int nrand(int n)
{
        if (n <= 0) throw domain_error("Argument to nrand is out of range");
		if (n > RAND_MAX) n %= RAND_MAX;
                

        const int bucket_size = RAND_MAX / n;
        int r;

        do r = rand() / bucket_size;
        while (r >= n);

        return r;

} 





