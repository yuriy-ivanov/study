// Task 13.0. - Source from book.
// Task 13.1. - Enhance Core and Grad ctors to identify ctor and its arguments.
//              Provide app to verify every ctor.
// Task 13.3. - Add member-function 'valid' from chap 9 to Core/Grad classes.
// Task 13.4. - Add function that represents digit mark as alpha mark as in chap 10.3.
// Task 13.5. - Implement predicate to verify students. If all homework is done and
//				if student is graduate - thesis mark.
// Task 13.6. - Add a class to represent students evaluated by zachot. These students
//				may do homework. If homework is done - final grade evaluated with homework mark.
//				Success grade for these students is 60+ points.
// Task 13.7. - Add a class to represent students that pass tests.
// Task 13.8. - Create app to generate all four kind of students report.

#include "misc.hpp"
#include <iomanip>

int main() {

	std::vector<misc::Student_info> students;
	misc::Student_info record;

	std::string::size_type maxlen = 0;

	while (record.read(std::cin)) {
		maxlen = std::max(maxlen, record.name().size());
		students.push_back(record);
	}

	std::sort(students.begin(), students.end(), misc::Student_info::compare);

	for (std::vector<Student_info>::size_type i = 0;
			i != students.size(); ++i) {
		std::cout << students[i].name()
				<< std::string(maxlen + 1 - students[i].name().size(), ' ');

		try {
			double final_grade = students[i].grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade
					<< std::setprecision(prec) << std::endl;
		} catch (std::domain_error& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
