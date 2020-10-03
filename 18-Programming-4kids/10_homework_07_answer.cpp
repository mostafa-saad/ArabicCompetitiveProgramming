#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	const int MAX = 270 + 500 + 1;
	int frequency[MAX] = { 0 };	// initialize with zeros. You can't do for other values (e.g. 1) this way.

	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;

		value += 500;	// shift all values to be positive
		frequency[value]++;
	}

	int mx_pos = 0;
	for (int i = 1; i < MAX; i++) {
		if (frequency[mx_pos] < frequency[i])
			mx_pos = i;
	}
	cout << mx_pos - 500 << " has repeated " << frequency[mx_pos] << " times ";
}
