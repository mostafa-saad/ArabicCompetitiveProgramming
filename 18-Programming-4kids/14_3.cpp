#include <iostream>
using namespace std;

struct emplyee {
	string name;
	int age;
	double salary;
	char gender;

	void read_employee() {
		cout << "Enter employee 4 entries: ";
		cin >> name >> age;
		cin >> salary >> gender;
	}

	void print_employee() {
		cout << name << " has salary " << salary << "\n";
	}

	int get_age() {
		return age;
	}
	void set_age(int new_age) {
		age = new_age;
	}
};

const int MAX = 10000;

emplyee emplyees_arr[MAX];
int added = 0;	// Number of employees

void print_employees() {
	for (int i = 0; i < added; ++i)
		emplyees_arr[i].print_employee();
}

int main() {
	emplyees_arr[added++].read_employee();
	emplyees_arr[added++].read_employee();
	print_employees();
	return 0;
}

