/*
 */

#include<iostream>
using namespace std;

int main() {
	int N;

	cin >> N;

	int row = N;
	while (row > 0) {
		int stars_count = 1;

		while (stars_count <= row) {
			cout << '*';
			++stars_count;
		}
		cout << "\n";
		row--;
	}

	return 0;
}

