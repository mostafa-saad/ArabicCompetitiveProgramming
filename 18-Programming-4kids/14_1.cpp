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

void read_employee() {
	cout<<"Enter employee 4 entries: ";
	cin >> emplyees_arr[added].name >> emplyees_arr[added].age;
	cin >> emplyees_arr[added].salary >> emplyees_arr[added].gender;
	added++;
}

void print_employees() {
	for (int i = 0; i < added; ++i) {
		emplyee e = emplyees_arr[i];
		cout << e.name << " has salary " << e.salary << "\n";
	}
}

int main() {
	emplyee first = { "mostafa", 10, 1200.5, 'M' };
	emplyees_arr[added++] = first;

	emplyees_arr[added].name = "hani";
	emplyees_arr[added].age = 55;
	emplyees_arr[added].salary = 750;
	emplyees_arr[added].gender = 'M';
	added++;

	read_employee();
	print_employees();
	return 0;
}

