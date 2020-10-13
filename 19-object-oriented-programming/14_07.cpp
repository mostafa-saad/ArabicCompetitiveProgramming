#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
	int id;
	int salary;
	string name;

	Employee(int id, int salary, string name) :
			id(id), salary(salary), name(name) {
	}
	bool operator <(const Employee & c2) {
		return std::tie(id, salary, name) <
			   std::tie(c2.id, c2.salary, c2.name);
	}

	void print() {
		cout << id << " " << name << " " << salary << "\n";
	}
};

void test1() {
	vector<Employee> emps;

	emps.push_back( { 9, 500, "ali" });
	emps.push_back( { 1, 1000, "mostafa" });
	emps.push_back( { 5, 700, "hani" });

	sort(emps.begin(), emps.end());	// overloaded <

	for (auto &emp : emps)
		emp.print();
}

class EmployeeComparatorId {
public:
	bool operator ()(const Employee & c1, const Employee & c2) {
		return c1.id < c2.id;
	}
};

class EmployeeComparatorSalary {
public:
	bool operator ()(const Employee & c1,
					 const Employee & c2) {
		return c1.salary < c2.salary;
	}
};

void test2() {
	vector<Employee> emps;

	emps.push_back( { 9, 500, "ali" });
	emps.push_back( { 1, 1000, "mostafa" });
	emps.push_back( { 5, 700, "hani" });

	EmployeeComparatorSalary comparator =
			EmployeeComparatorSalary();
	sort(emps.begin(), emps.end(), comparator);

	for (auto &emp : emps)
		emp.print();
}

void test3() {
	vector<Employee> emps;

	emps.push_back( { 9, 500, "ali" });
	emps.push_back( { 1, 1000, "mostafa" });
	emps.push_back( { 5, 700, "hani" });

	sort(emps.begin(), emps.end(), [](const Employee & c1,
					 const Employee & c2) {
		return c1.salary < c2.salary;
		});

	for (auto &emp : emps)
		emp.print();
}

int main() {
	test3();

	return 0;
}
