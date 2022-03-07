#include<iostream>
using namespace std;

int main() {
	int n, tmp, mn[3];

	cin >> n;
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;

		if (i < 3)
			mn[i] = value;
		else {
			// Find maximum position
			int mx_pos = 0;
			for (int j = 1; j < 3; ++j) {
				if (mn[mx_pos] < mn[j])
					mx_pos = j;
			}

			if (value < mn[mx_pos])
				mn[mx_pos] = value;
		}
	}

	// let's order the first 3 values. We can do in several ways
	// Find maximum position
	int mx_pos = 0;
	for (int j = 1; j < 3; ++j) {
		if (mn[mx_pos] < mn[j])
			mx_pos = j;
	}
	// swap max with last
	tmp = mn[2];
	mn[2] = mn[mx_pos];
	mn[mx_pos] = tmp;

	// Swap first 2 elements if needed
	if (mn[0] > mn[1]) {
		tmp = mn[0];
		mn[0] = mn[1];
		mn[1] = tmp;
	}

	for (int i = 0; i < 3; i++)
		cout << mn[i] << " ";	// not ordered


	return 0;
}
