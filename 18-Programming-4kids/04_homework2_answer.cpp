/*

A teacher want a program that reads 2 students information about math exam
	Read per student: name, id and grade
	Then print them. See the picture in the slides


Be a good software engineer
	Think deeply in your selected data types
	The teacher gives us this dialogue to guide us
	Be careful from your assumptions?
	Is exam’s grade an integer?


*/

#include<iostream>
using namespace std;

int main() {
	string name1;
	cout<<"What is student 1 name: ";
	cin>>name1;

	// Although looks as integer, no guarantee (make be big or has letters)
	string id1;
	cout<<"His id: ";
	cin>>id1;

	// Although looks as integer, but grade could be 30.5
	double grade1;
	cout<<"His math exam grade: ";
	cin>>grade1;

	/////////////////////////
	string name2;
	cout<<"What is student 2 name: ";
	cin>>name2;

	string id2;
	cout<<"His id: ";
	cin>>id2;

	double grade2;
	cout<<"His math exam grade: ";
	cin>>grade2;

	cout<<"\nStudents grades in math\n";

	cout<<name1<<" (with id "<<id1<<") got grade: "<<grade1<<"\n";
	cout<<name2<<" (with id "<<id2<<") got grade: "<<grade2<<"\n";
	cout<<"Average grade is "<<(grade1 + grade2) / 2.0<<"\n";

	return 0;
}

