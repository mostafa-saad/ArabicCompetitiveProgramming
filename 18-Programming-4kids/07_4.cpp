#include<iostream>
using namespace std;

int main() {
	int salary;

	cout<<"Enter salary: ";
	cin>>salary;

	if (salary < 1000)
	{
		cout<<"Enter age: ";
		int age;
		cin>>age;

		if (age < 22)
			cout<<"You are still young.";
	}
	else
		cout<<"you are rich\n";

	//cout<<age; 	// NOT visible outside scope

	return 0;
}

