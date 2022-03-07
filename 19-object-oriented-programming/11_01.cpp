#include <bits/stdc++.h>
using namespace std;

class Person {
protected:
	string name;

public:
	Person() : name("most") {
		cout << "Person Default Constructor\n";
	}
	Person(string name) :
			name(name) {
		cout << "Person 2nd Constructor\n";
	}
	~Person() {
		cout<<"Person Destructor\n";
	}
};

class Student : public Person {
private:
	double gpa;
public:
	Student() {		// CE: name("hani") you can't access base here
		cout << "Student Default Constructor\n";
		gpa = 0;
		name = "hani";	// you can set here
	}
	Student(double gpa) : Person("Ali"), gpa(gpa) {
		cout << "Student 2nd Constructor\n";
	}
	~Student() {
		cout<<"Student Destructor\n";
	}
};

int main() {
	Student student1;
	Student student2(3.0);
	return 0;
}
