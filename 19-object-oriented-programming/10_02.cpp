#include <bits/stdc++.h>
using namespace std;

class Person {
public:
	string name = "Mostafa";
	string email = "most@gmail";

	bool IsValidEmailFormat() {
		return true;
	}
};

class Student: public Person {
private:
	double GPA;

public:
	void PrintGrades() {
		cout << name << " GPA=" << GPA << "\n";
	}

	void SetGpa(double gpa) {
		GPA = gpa;
	}
};

int main() {
	Student student;

	// Student is a person.
	student.SetGpa(3.5);
	student.IsValidEmailFormat();
	student.PrintGrades();

	//Person is not necessarily a student
	Person person;
	person.IsValidEmailFormat();
	//person.PrintGrades();	// no nothing about student!

	return 0;
}
