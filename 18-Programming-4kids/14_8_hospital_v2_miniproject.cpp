#include<iostream>
using namespace std;

// Global variables
const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

struct hospital_queue {
	string names[MAX_QUEUE];
	int status[MAX_QUEUE];
	int len;
	int spec;

	hospital_queue() {
		len = 0;
		spec = -1;
	}

	hospital_queue(int _spec) {
		len = 0;
		spec = _spec;
	}

	bool add_end(string name, int st) {
		if (len == MAX_QUEUE)
			return false;
		names[len] = name, status[len] = st, ++len;
		return true;
	}
	bool add_front(string name, int st) {
		if (len == MAX_QUEUE)
			return false;
		// Shift right
		for (int i = len - 1; i >= 0; --i) {
			names[i + 1] = names[i];
			status[i + 1] = status[i];
		}
		names[0] = name, status[0] = st, len++;
		return true;
	}

	void remove_front() {
		if (len == 0) {
			cout << "No patients at the moment. Have rest, Dr\n";
			return;
		}
		cout << names[0] << " please go with the Dr\n";

		// Shift left
		for (int i = 1; i < len; ++i) {
			names[i - 1] = names[i];
			status[i - 1] = status[i];
		}
		--len;
	}

	void print() {
		if (len == 0)
			return;

		cout << "There are " << len << " patients in specialization " << spec << "\n";
		for (int i = 0; i < len; ++i) {
			cout << names[i] << " ";
			if (status[i])
				cout << "urgent\n";
			else
				cout << "regular\n";
		}
		cout << "\n";
	}
};

struct hospital_system {
	hospital_queue queues[MAX_SPECIALIZATION+1];

	hospital_system() {
		for (int i = 0; i < MAX_SPECIALIZATION; ++i)
			queues[i] = hospital_queue(i);
	}

	void run() {
		while (true) {
			int choice = menu();

			if (choice == 1)
				add_patient();
			else if (choice == 2)
				print_patients();
			else if (choice == 3)
				get_next_patients();
			else
				break;
		}
	}

	int menu() {
		int choice = -1;
		while (choice == -1) {
			cout << "\nEnter your choice:\n";
			cout << "1) Add new patient\n";
			cout << "2) Print all patients\n";
			cout << "3) Get next patient\n";
			cout << "4) Exit\n";

			cin >> choice;

			if (!(1 <= choice && choice <= 4)) {
				cout << "Invalid choice. Try again\n";
				choice = -1;	// loop keep working
			}
		}
		return choice;
	}

	bool add_patient() {
		int spec, st;
		string name;

		cout << "Enter specialization, name, status: ";
		cin >> spec >> name >> st;

		bool status;
		if (st == 0)
			status = queues[spec].add_end(name, st);
		else
			status = queues[spec].add_front(name, st);

		if (status == false) {
			cout<< "Sorry we can't add more patients for this specialization\n";
			return false;
		}

		return true;
	}

	void print_patients() {
		cout << "****************************\n";
		for (int spec = 0; spec < MAX_SPECIALIZATION; ++spec)
			queues[spec].print();
	}

	void get_next_patients() {
		int spec;
		cout << "Enter specialization: ";
		cin >> spec;

		queues[spec].remove_front();
	}
};

int main() {
	freopen("c.in", "rt", stdin);
	hospital_system hospital = hospital_system();
	hospital.run();
	return 0;
}

