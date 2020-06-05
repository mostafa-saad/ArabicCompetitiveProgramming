#include <iostream>
using namespace std;

struct emplyee {
	string name;
	int age;
	double salary;
	char gender;
};

const int MAX = 10000;

emplyee emplyees_arr[MAX];
int added = 0;	// Number of employees

void read_employee(emplyee & e) {
	cout << "Enter employee 4 entries: ";
	cin >> e.name >> e.age;
	cin >> e.salary >> e.gender;
}

void print_employee(emplyee & e) {
	cout << e.name << " has salary " << e.salary << "\n";
}
void print_employees() {
	for (int i = 0; i < added; ++i)
		print_employee(emplyees_arr[i]);
}

int main() {
	read_employee(emplyees_arr[added++]);
	read_employee(emplyees_arr[added++]);
	print_employees();
	return 0;
}

