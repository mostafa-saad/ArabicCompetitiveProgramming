#include<iostream>
using namespace std;

int main() {
	int salary;
	cin>>salary;

	if (salary < 1000)
		cout<<"you are poor\n";
	else if (salary >= 1000 && salary < 20000)
		cout<<"good salary\n";
	else
		cout<<"you are rich\n";

	return 0;
}

