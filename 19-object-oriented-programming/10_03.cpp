#include <bits/stdc++.h>
using namespace std;

class Person {
protected:
	// Act as private for outsiders
	// But inherited children can see it
	string name = "Mostafa";
	string email = "most@gmail";

public:
	bool IsValidEmailFormat() {
		return true;
	}
};

class Student: public Person {
private:
	double GPA;

public:
	void PrintGrades() {
		// Now we can see name again, but outsiders can't
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
	//person.email;		// can't: protected is like private for outsiders
	person.IsValidEmailFormat();
	//person.PrintGrades();	// no nothing about student!

	return 0;
}
