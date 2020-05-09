#include<iostream>
using namespace std;

int main() {
	//freopen("c.in", "rt", stdin);

	const int MAX = 10000;

	string names[MAX];
	int ages[MAX];
	double salaries[MAX];
	char genders[MAX];
	int added = 0;	// Number of employees

	while (true) {
		int choice = -1;
		cout << "\nEnter your choice:\n";
		cout << "1) Add new employee\n";
		cout << "2) Print all employees\n";
		cout << "3) Delete by age\n";
		cout << "4) Update Salary by name\n";

		cin >> choice;

		//if (cin.fail())			break;

		if (!(1 <= choice && choice <= 4)) {
			cout << "Invalid choice. Try again\n";
			continue;
		}

		if (choice == 1) {
			cout << "Enter name: ";
			cin >> names[added];

			cout << "Enter age: ";
			cin >> ages[added];

			cout << "Enter salary: ";
			cin >> salaries[added];

			cout << "Enter gender (M/F): ";
			cin >> genders[added];
			++added;
		} else if (choice == 2) {
			cout << "****************************\n";
			for (int i = 0; i < added; ++i) {
				if (ages[i] != -1)
					cout << names[i] << " " << ages[i] << " " << salaries[i]
							<< " " << genders[i] << "\n";
			}
		} else if (choice == 3) {
			cout << "Enter start and end age: ";
			int start, end;
			cin >> start >> end;

			for (int i = 0; i < added; ++i) {
				if (start <= ages[i] && ages[i] <= end)
					ages[i] = -1;// Let's mark a removed entry with -1 (lazy delete)
			}
		} else {
			cout << "Enter the name and salary: ";
			string name;
			int salary;
			cin >> name >> salary;

			bool is_found = false;
			for (int i = 0; i < added; ++i) {
				if (ages[i] != -1 && names[i] == name) {
					is_found = true;
					salaries[i] = salary;
					break;
				}
			}
			if (!is_found)
				cout << "No employee with this name!\n";
		}
	}
	return 0;
}

