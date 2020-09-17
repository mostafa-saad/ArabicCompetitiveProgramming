#include <bits/stdc++.h>
using namespace std;

class Person {
public:
	virtual void print() {	cout << "Person\n";	}
	virtual ~Person()	 {	cout << "~Person\n";}
};

class Student: public Person {
public:
	void print() {	cout << "Student\n";	}
	~Student()	 {	cout << "~Student\n";}
};


int main() {
	Person* stud_ptr3 = new Student();
	stud_ptr3->print();
	stud_ptr3->Person::print();	// Explicit

	delete stud_ptr3;

	/*
Student
~Student
~Person
	 *
	 */

	return 0;
}


int main2() {
	Person person;	// first object
	Student stud;	// 2nd object

	person.print();
	stud.print();

	Person* per_ptr = &person;
	Student* stud_ptr1 = &stud;
	Person* stud_ptr2 = &stud;
	Person* stud_ptr3 = new Student();	// 3rd object

	per_ptr->print();
	stud_ptr1->print();
	stud_ptr2->print();
	stud_ptr3->print();

	delete stud_ptr3;

	return 0;
}

/*
Person
Student
Person
Student
Person
Person
~Student		from 3rd object: derived
~Person			from 3rd object: base
~Student		from 2nd object: derived
~Person			from 2nd object: base
~Person		    from first object

 */
