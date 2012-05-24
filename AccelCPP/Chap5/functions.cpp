#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include "functions.h"
#include "chap5tasks\task_5_0\StdAfx.h"

using namespace std;

double average(const vector<double>& vec)
{
	if (vec.size() == 0) throw domain_error("Empty vector");
	double summ = 0.0;
	for (vector<double>::size_type i = 0; i < vec.size(); ++i) summ += vec[i];
	return summ / (double)vec.size();
}
double median(vector<double>& vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0) throw domain_error("Empty vector mediate");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid+1]) / 2 : vec[mid];
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
bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
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

	try { s.final_grade = grade(midterm, final, homework); }
	catch (domain_error e) { cout << e.what(); }

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
		if (is) {
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
vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for (vector<string>::size_type i = 0; i < v.size(); ++i){
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

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

	while (i != left.size() || j != right.size()) {
		string s;

		if (i != left.size()) s = left[i++];

		s += string(width1 - s.size(), ' ');

		if (j != right.size()) s += right[j++];

		ret.push_back(s);
	}
	return ret;
}
void output(ostream& os, const vector<string>& v)
{
	for (vector<string>::size_type i = 0; i < v.size(); ++i) os << v[i] << endl;
}
string randomStrGen(int length) {
    static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
    result.resize(length);

    //srand(time(NULL));
    for (int i = 0; i < length; i++)
        result[i] = charset[rand() % charset.length()];

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