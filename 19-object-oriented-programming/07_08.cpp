#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
	string name;
	static int employees_count;

public:
	Employee(string name) :
			name(name) {
		++Employee::employees_count;
	}
	static int GetEmployeeCount() {
		return Employee::employees_count;
	}
};

int Employee::employees_count = 0;

int main() {
	Employee most("Mostafa");
	Employee("Mona");
	static Employee belal("Belal");

	cout << Employee::GetEmployeeCount();	// 3

	return 0;
}
