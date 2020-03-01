#include<iostream>
using namespace std;

int main() {
	int age = 30, salary = 7000, weight = 110;

	cout<<(  (age > 25) && (salary < 8000) && (weight < 150) )<<"\n";
	cout<<(  (age > 25) && (salary < 8000) && (weight > 200) )<<"\n";

	cout<<(  (age > 35) || (salary > 6000) || (weight > 200) )<<"\n";

	cout<<(  (age > 35) && (salary > 6000) || (weight > 200) )<<"\n";
	cout<<(  (age > 20) && (salary > 6000) || (weight > 200) )<<"\n";

	return 0;
}

