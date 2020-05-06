#include<iostream>
using namespace std;

int main() {
	double grades[7][6] = { 0 };

	for (int row = 0; row < 7; ++row)
		for (int col = 0; col < 4; ++col)
			cin >> grades[row][col];

	for (int col = 0; col < 4; ++col) {
		cout << "Col " << col << ": ";
		for (int row = 0; row < 7; ++row) {
			cout << grades[row][col] << " ";
		}
		cout << "\n";
	}
	return 0;
}

