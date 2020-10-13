#include <bits/stdc++.h>
using namespace std;

class Person {
public:
	void print() {	cout << "Person\n";	}
	~Person()	 {	cout << "~Person\n";}
};

class Student: public Person {
public:
	void print() {	cout << "Student\n";	}
	~Student()	 {	cout << "~Student\n";}
};

int main() {
	Person person;	// first object
	Student stud;	// 2nd object

	person.print();
	stud.print();

	// No object construct/deconstruct for the refrence
	Person* per_ptr = &person;
	Student* stud_ptr1 = &stud;
	Person* stud_ptr2 = &stud;
	Person* stud_ptr3 = new Student();	// 3rd object

	per_ptr->print();
	stud_ptr1->print();
	stud_ptr2->print();	// Call Person not Student
	stud_ptr3->print();	// Call Person not Student

	delete stud_ptr3;	// Memory leak

	return 0;
}

/*
Person
Student
Person
Student
Person
Person
~Person			from 3rd object: memory leak: student is not cleaned
~Student		from 2nd object: derived
~Person			from 2nd object: base
~Person		    from first object
 */
