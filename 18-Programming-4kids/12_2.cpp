#include<iostream>
using namespace std;

int main() {
	double grades[7][6] = { 0 };

	// Mostafa Grades
	grades[0][0] = 50, grades[0][1] = 33, grades[0][2] = 40, grades[0][3] = 30;

	// Asmaa Grades
	grades[1][0] = 35, grades[1][1] = 50, grades[1][2] = 40, grades[1][3] = 30;

	for (int row = 0; row < 7; ++row) {
		cout << "Row " << row << ": ";
		for (int col = 0; col < 4; ++col) {
			cout << grades[row][col] << " ";
		}
		cout << "\n";
	}
	return 0;
}

