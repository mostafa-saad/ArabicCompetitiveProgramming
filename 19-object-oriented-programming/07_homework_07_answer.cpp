#include <bits/stdc++.h>
using namespace std;

class StudentGradesInfo {
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;
	const int MAX_GRADE_PER_COURSE = 100.0;

	static int statistics_total_prints;

	double AdjustGrade(double grade) const {
		if (grade < 0)
			return 0;
		if (grade > MAX_GRADE_PER_COURSE)
			return MAX_GRADE_PER_COURSE;
		return grade;
	}
public:

	StudentGradesInfo(string student_id) :
			student_id(student_id) {
	}

	bool AddGrade(double grade, const string &course_name) {
		grade = AdjustGrade(grade);

		for (int i = 0; i < (int) courses_names.size(); ++i)
			if (course_name == courses_names[i])
				return false;	// already added

		grades.push_back(grade);
		courses_names.push_back(course_name);
		return true;
	}
	void PrintAllCourses() const {
		++statistics_total_prints;

		cout << "Grades for student: " << GetStudentId() << "\n";
		for (int course_idx = 0; course_idx < (int) courses_names.size(); ++course_idx)
			cout << "\t" << courses_names[course_idx] << " = " << grades[course_idx] << "\n";
	}
	bool GetCourseGradeInfo(int pos, pair<string, double> &result) const {
		if (pos < 0 || pos >= (int) grades.size()) {
			result = make_pair("", -1);
			return false;
		}
		result = make_pair(courses_names[pos], grades[pos]);
		return true;
	}

	string GetStudentId() const {
		return student_id;
	}

	int GetTotalCoursesCount() const {
		return grades.size();
	}

	pair<double, double> GetTotalGradesSum() const {
		double sum = 0, total = 0;
		for (int grade_idx = 0; grade_idx < (int) grades.size(); ++grade_idx)
			sum += grades[grade_idx], total += MAX_GRADE_PER_COURSE;
		return make_pair(sum, total);
	}
};

int StudentGradesInfo::statistics_total_prints = 0;

class StudentGradesInfoPrinter {
private:
	const StudentGradesInfo & student_info;
	int cur_course_pos = 0;

public:
	// Make it object by reference to feel updates. Const to never change its content as printer
	StudentGradesInfoPrinter(const StudentGradesInfo & student_info) :
			student_info(student_info) {
	}

	void ResetIterator() {
		cur_course_pos = 0;	// from scratch
	}

	bool HasNext() const {
		// just make sure still smaller position
		return cur_course_pos < student_info.GetTotalCoursesCount();
	}

	pair<string, double> GetNext() {
		// return next item
		pair<string, double> result;
		student_info.GetCourseGradeInfo(cur_course_pos++, result);
		return result;
	}
};

/*

You just learned 2 things:

1- Open–closed principle
"Software entities ... should be open for extension, but closed for modification."
We managed to extend the functionality of the class to ore controlled printing. We did not need to change original code

2- Iterator Design Pattern
- HasNext / GetNext is a general strategy to allow iterating on something
- STL has iterators on several containers


 */

int main() {
	StudentGradesInfo st1("S000123");
	StudentGradesInfoPrinter printer(st1);

	st1.AddGrade(50, "Math");
	st1.AddGrade(60, "programming 1");

	int limit = 3;
	cout << "Printing top " << limit << " Grades, if available\n";
	while (limit-- && printer.HasNext()) {
		pair<string, double> result = printer.GetNext();

		cout << "\t" << result.first << " = " << result.second << "\n";
	}

	st1.AddGrade(70, "Algorithms");
	st1.AddGrade(67, "programming 2");

	printer.ResetIterator();
	limit = 3;
	cout << "\nPrinting top " << limit << " Grades, if available\n";
	while (limit-- && printer.HasNext()) {
		pair<string, double> result = printer.GetNext();

		cout << "\t" << result.first << " = " << result.second << "\n";
	}

	return 0;
}
