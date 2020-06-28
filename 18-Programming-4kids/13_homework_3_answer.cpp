#include<iostream>
using namespace std;

int menu() {
	int choice = -1;
	while (choice == -1) {
		if (true) {
			cout << "\nMenu;\n";
			cout << "1) Add 2 numbers\n";
			cout << "2) Subtract 2 numbers\n";
			cout << "3) Multiply 2 numbers\n";
			cout << "4) Divide 2 numbers\n";
			cout << "5) Exit\n";
		}

		cout << "\nEnter your menu choice [1 - 5]: ";
		cin >> choice;

		if (!(1 <= choice && choice <= 5)) {
			cout << "Invalid choice. Try again\n";
			choice = -1;	// loop keep working
		}
	}
	return choice;
}

void read_2_num(double &a, double &b) {
	cout << "Enter 2 numbers: ";
	cin >> a >> b;
}

void add(double a, double b) {
	cout << "a + b = " << a + b << "\n";
}

void subtract(double a, double b) {
	cout << "a - b = " << a - b << "\n";
}

void multiply(double a, double b) {
	cout << "a * b = " << a * b << "\n";
}

void divide(double a, double b) {
	if (b != 0)
		cout << "a / b = " << a / b << "\n";
	else
		cout << "can't divide by zero\n";
}

int main() {
	int total_operations = 0;
	double a, b;

	while (true) {
		int choice = menu();

		if (choice == 5)
			break;

		total_operations++;

		read_2_num(a, b);

		if (choice == 1)
			add(a, b);
		else if (choice == 2)
			subtract(a, b);
		else if (choice == 3)
			multiply(a, b);
		else if (choice == 4)
			divide(a, b);
	}
	cout << "Total operations: " << total_operations;

	return 0;
}
