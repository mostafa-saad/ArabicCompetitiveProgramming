#include <bits/stdc++.h>
using namespace std;



class Student {
private:
	string name;
	string email;
	string address;
	string natioal_id;

	int starting_study_year;
	double GPA;
	vector<int> studied_courses;
public:
	bool IsValidEmailFormat();
	void AddCourseGrade(int course_id, double grade);
	void PrintGrades();
};

class Teacher {
private:
	string name;
	string email;
	string address;
	string natioal_id;

	int starting_employement_year;
	double current_salary;
	vector<int> teaching_courses;
public:
	bool IsValidEmailFormat();
	void AddCourse(int course_id);
};


int main() {

	return 0;
}
