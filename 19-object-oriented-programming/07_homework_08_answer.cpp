#include <bits/stdc++.h>
using namespace std;

class StudentGradesInfo {
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;
	const int MAX_GRADE_PER_COURSE = 100.0;

	friend class StudentGradesInfoWhiteBoxTester;	// as a friend

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

class StudentGradesInfoWrapper {
private:
	StudentGradesInfo student_info;

	static int statistics_total_prints;
	static int statistics_total_students;
public:

	StudentGradesInfoWrapper(string student_id) :
			student_info(StudentGradesInfo(student_id)) {
		++statistics_total_students;
	}

	bool AddGrade(double grade, const string &course_name) {
		return student_info.AddGrade(grade, course_name);
	}

	void PrintAllCourses() const {
		// Sadly StudentGradesInfoWrapper is not fully extensible. We can't retrieve statistics_total_prints
		// Let's redo the work
		++statistics_total_prints;

		student_info.PrintAllCourses();
	}
	bool GetCourseGradeInfo(int pos, pair<string, double> &result) const {
		return student_info.GetCourseGradeInfo(pos, result);
	}

	string GetStudentId() const {
		return student_info.GetStudentId();
	}

	int GetTotalCoursesCount() const {
		return student_info.GetTotalCoursesCount();

	}

	pair<double, double> GetTotalGradesSum() const {
		return student_info.GetTotalGradesSum();
	}

	int static GetTotalPrints() {
		return statistics_total_prints;
	}
	int static GetTotalStudents() {
		return statistics_total_students;
	}
};

int StudentGradesInfoWrapper::statistics_total_prints = 0;
int StudentGradesInfoWrapper::statistics_total_students = 0;

/*
In real life, we may use some open source code
But what if we later discovered it is so buggy and need replacement?
Or team stopped maintenance and we need more features?

It is better in these conditions to WRAP them so that your code
depends on the wrapper
Once u decided to change the wrapper, everything else in ur code did not change

It is important to design code that changes very little

Reading: https://stackoverflow.com/questions/889160/what-is-a-wrapper-class
 */

int main() {
	StudentGradesInfoWrapper st1("S000123");
	st1.AddGrade(70, "Math");
	st1.AddGrade(70, "programming 1");
	st1.AddGrade(85, "programming 2");

	st1.PrintAllCourses();

	pair<double, double> p = st1.GetTotalGradesSum();
	cout << p.first << "/" << p.second << "\n";

	StudentGradesInfoWrapper st2("S000129");
	st2.PrintAllCourses();
	st2.PrintAllCourses();
	st2.PrintAllCourses();

	cout << "Total Students " << StudentGradesInfoWrapper::GetTotalStudents() << "\n";
	cout << "Total Prints " << StudentGradesInfoWrapper::GetTotalPrints() << "\n";

	cout << "Bye\n";

	return 0;
}
