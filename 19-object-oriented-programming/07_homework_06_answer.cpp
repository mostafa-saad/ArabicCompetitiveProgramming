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
	bool GetCourseGradeInfo(int pos, pair<string, double> &result) {
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


////////////////////////////

class StudentGradesInfoBlaxBoxTester {
private:
	const static int MAX_GRADE_PER_COURSE = 100.0;
public:

	void static Test_TotalCoursesCount() {
		cout << __func__ << "\n";		// print fuction name
		StudentGradesInfo st1("S000123");
		assert(st1.GetTotalCoursesCount() == 0);
		st1.AddGrade(70, "Math");
		st1.AddGrade(70, "programming 1");
		st1.AddGrade(85, "programming 2");
		assert(st1.GetTotalCoursesCount() == 3);

		st1.AddGrade(75, "programming 2");
		st1.AddGrade(65, "programming 2");
		st1.AddGrade(95, "programming 2");
		assert(st1.GetTotalCoursesCount() == 3);

		assert(st1.GetStudentId() == "S000123");

	}

	void static Test_TotalGradesSum() {
		cout << __func__ << "\n";
		pair<double, double> p;

		StudentGradesInfo st1("S000123");
		p = st1.GetTotalGradesSum();
		assert(p.first == 0);
		assert(p.second == 0);

		st1.AddGrade(200, "Math");
		p = st1.GetTotalGradesSum();
		assert(p.first == MAX_GRADE_PER_COURSE);
		assert(p.second == MAX_GRADE_PER_COURSE);

		st1.AddGrade(70, "programming 1");
		p = st1.GetTotalGradesSum();
		assert(p.first == 70 + MAX_GRADE_PER_COURSE);
		assert(p.second == 2 * MAX_GRADE_PER_COURSE);

		// If readded, make sure not updated
		st1.AddGrade(60, "programming 1");	// try lower
		p = st1.GetTotalGradesSum();
		assert(p.first == 70 + MAX_GRADE_PER_COURSE);
		assert(p.second == 2 * MAX_GRADE_PER_COURSE);

		// If readded, make sure not updated
		st1.AddGrade(80, "programming 1");	// try bigger
		p = st1.GetTotalGradesSum();
		assert(p.first == 70 + MAX_GRADE_PER_COURSE);
		assert(p.second == 2 * MAX_GRADE_PER_COURSE);

		st1.AddGrade(85, "programming 2");
		p = st1.GetTotalGradesSum();
		assert(p.first == 85 + 70 + MAX_GRADE_PER_COURSE);
		assert(p.second == 3 * MAX_GRADE_PER_COURSE);

		if (false) {
			// This will fail. We should handle the code to not be case sensetive!
			st1.AddGrade(85, "PROGramming 2");
			p = st1.GetTotalGradesSum();
			assert(p.first == 85 + 70 + MAX_GRADE_PER_COURSE);
			assert(p.second == 3 * MAX_GRADE_PER_COURSE);
		}

	}

	void static Test_GetCourseGradeInfo() {
		cout << __func__ << "\n";
		StudentGradesInfo st1("S000123");
		assert(st1.GetTotalCoursesCount() == 0);
		st1.AddGrade(200, "Math");
		st1.AddGrade(70, "programming 1");

		pair<string, double> result;
		assert(st1.GetCourseGradeInfo(st1.GetTotalCoursesCount(), result) == false);
		assert(st1.GetCourseGradeInfo(-5, result) == false);

		st1.GetCourseGradeInfo(0, result);
		assert(result.first == "Math");
		assert(result.second == MAX_GRADE_PER_COURSE);

		st1.GetCourseGradeInfo(1, result);
		assert(result.first == "programming 1");
		assert(result.second == 70);
	}

	void static Test_PrintAllCourses() {
		cout << __func__ << "\n";
		// This function is writing to console! How to test?
		// 1) use Freopen to direct output to file
		// 2) read file content
		// 3) compare to what you expect!
	}

	void static TestAll() {
		Test_TotalCoursesCount();
		Test_TotalGradesSum();
		Test_GetCourseGradeInfo();
		Test_PrintAllCourses();

		cout<<"Black box: Passed all unit tests\n";
	}
};
//////////////////////////////////////////////

// One bad issue in white testing, it is very "coupled" with the class
// Any change in above code may change here too!
class StudentGradesInfoWhiteBoxTester {
private:
	const static int MAX_GRADE_PER_COURSE = 100.0;
public:

	void static Test_AdjustGrade() {
		cout << __func__ << "\n";

		StudentGradesInfo st1("S000123");
		assert(st1.AdjustGrade(50.1) == 50.1);
		assert(st1.AdjustGrade(-200) == 0);
		assert(st1.AdjustGrade(200) == 100);
		assert(st1.AdjustGrade(70 == 70));	// can spot coding bug?
	}

	void static Test_AddGrade() {
		cout << __func__ << "\n";

		StudentGradesInfo st1("S000123");

		st1.AddGrade(200, "Math");
		assert(st1.courses_names.size() == st1.grades.size() && st1.courses_names.size() == 1);

		st1.AddGrade(70, "programming 1");
		assert(st1.courses_names.size() == st1.grades.size() && st1.courses_names.size() == 2);

		st1.AddGrade(60, "programming 1");
		assert(st1.courses_names.size() == st1.grades.size() && st1.courses_names.size() == 2);
		assert(st1.grades.back() == 70);	// not updated
		assert(st1.courses_names.back() == "programming 1");
	}

	void static Test_statistics_total_prints() {
		cout << __func__ << "\n";

		StudentGradesInfo st1("S000123");
		StudentGradesInfo st2("S300123");

		assert(StudentGradesInfo::statistics_total_prints == 0);
		st1.PrintAllCourses();
		assert(StudentGradesInfo::statistics_total_prints == 1);

		st1.AddGrade(70, "programming 1");
		st1.PrintAllCourses();
		assert(StudentGradesInfo::statistics_total_prints == 2);
		st2.PrintAllCourses();
		assert(StudentGradesInfo::statistics_total_prints == 3);
	}
	// And so on

	void static TestAll() {
		StudentGradesInfoBlaxBoxTester::TestAll();

		Test_AdjustGrade();
		Test_AddGrade();
		Test_statistics_total_prints();

		cout<<"White box: Passed all unit tests\n";
	}
};

int main() {
	StudentGradesInfoWhiteBoxTester::TestAll();

	return 0;
}
