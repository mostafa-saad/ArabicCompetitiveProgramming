#include<iostream>
using namespace std;

int main() {
	double grades[7][6] = { 0 };

	for (int row = 0; row < 7; ++row)
		for (int col = 0; col < 4; ++col)
			cin >> grades[row][col];

	for (int row = 0; row < 7; ++row) {
		double sum = 0;
		for (int col = 0; col < 4; ++col)
			sum += grades[row][col];

		double avg = sum / 7.0;

		cout << "Student # " << row + 1
			 << " has average grade: " << avg << "\n";
	}
	return 0;
}

