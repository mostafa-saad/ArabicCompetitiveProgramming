#include <bits/stdc++.h>
using namespace std;

class Person {
protected:
	string name;
	string email;
	string address;
	string natioal_id;

public:
	bool IsValidEmailFormat() {return true;}

	void SetName(const string& name) {
		this->name = name;
	}
};

class Student: public Person {
private:
	int starting_study_year;
	double GPA;
	vector<int> studied_courses;

public:
	void AddCourseGrade(int course_id, double grade) {}
	void PrintGrades() {
		cout<<name<<" "<<GPA<<"\n";
	}

	void SetGpa(double gpa) {
		GPA = gpa;
	}
};

class Teacher: public Person {
private:
	int starting_employement_year;
	double current_salary;
	vector<int> teaching_courses;

public:
	void AddCourse(int course_id) {}

	void SetCurrentSalary(double currentSalary) {
		current_salary = currentSalary;
	}
};

int main() {
	Student student;
	student.SetGpa(3.5);
	student.PrintGrades();

	Teacher teacher;
	teacher.SetCurrentSalary(5000.0);

	return 0;
}
