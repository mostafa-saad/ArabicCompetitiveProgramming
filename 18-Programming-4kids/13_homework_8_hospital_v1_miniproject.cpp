#include<iostream>
using namespace std;

// Global variables
const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

string names[MAX_SPECIALIZATION+1][MAX_QUEUE+1];
int status[MAX_SPECIALIZATION+1][MAX_QUEUE+1];		// 0 regular, 1 urgent
int queue_length[MAX_SPECIALIZATION+1];			// for each specialization: how many patients so far

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

// Move each patient to the left. E.g if patient in position 5, it will be in 4
// Help in removing patient
void shift_left(int spec, string names_sp[], int status_sp[])
{
	int len = queue_length[spec];
	for (int i = 1; i < len; ++i) {
		names_sp[i-1] = names_sp[i];
		status_sp[i-1] = status_sp[i];
	}
	queue_length[spec]--;
}

// Move each patient to the right. E.g if patient in position 5, it will be in 6
// Help in adding patient
void shift_right(int spec, string names_sp[], int status_sp[])
{
	int len = queue_length[spec];
	for (int i = len-1; i >= 0; --i) {	// critical to start from END
		names_sp[i+1] = names_sp[i];
		status_sp[i+1] = status_sp[i];
	}
	queue_length[spec]++;
}

bool add_patient() {
	int spec;
	string name;
	int st;

	cout << "Enter specialization, name, statis: ";
	cin >> spec >> name >> st;

	int pos = queue_length[spec];
	if (pos >= MAX_QUEUE) {
		cout << "Sorry we can't add more patients for this specialization\n";
		return false;
	}

	if (st == 0)	// regular, add to end
	{
		names[spec][pos] = name;
		status[spec][pos] = st;
		queue_length[spec]++;
	}
	else {
		// urgent, add to begin. Shift, then add
		shift_right(spec, names[spec], status[spec]);
		names[spec][0] = name;
		status[spec][0] = st;
	}


	return true;
}

void print_patient(int spec, string names_sp[], int status_sp[]) {
	int len = queue_length[spec];
	if (len == 0)
		return;

	cout << "There are " << len << " patients in specialization " << spec << "\n";
	for (int i = 0; i < len; ++i) {
		cout << names_sp[i] << " ";
		if (status_sp[i])
			cout << "urgent\n";
		else
			cout << "regular\n";
	}
	cout << "\n";
}

void print_patients() {
	cout << "****************************\n";
	for (int spec = 0; spec < MAX_SPECIALIZATION; ++spec) {
		print_patient(spec, names[spec], status[spec]);
	}
}

void get_next_patients() {
	int spec;
	cout << "Enter specialization: ";
	cin >> spec;

	int len = queue_length[spec];

	if(len == 0) {
		cout<<"No patients at the moment. Have rest, Dr\n";
		return;
	}

	// Let patient goes to dr
	cout<<names[spec][0]<<" please go with the Dr\n";

	// delete the patient in position 0
	shift_left(spec, names[spec], status[spec]);
}

void hospital_system() {
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

int main() {
//freopen("c.in", "rt", stdin);
	hospital_system();
	return 0;
}

/*

1
15 mostafa 0
1 
15 asmaa 0
1
15 belal 1

2

1
15 ziad 1
2

1
15 safaa 0

1 15 ashraf
2

3
10

3
15

2

1
7 soha 1

2

1
15 amal 1

3
7

2

*/
