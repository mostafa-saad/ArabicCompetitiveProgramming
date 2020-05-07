#include<iostream>
using namespace std;

int main() {
	int n, upper = 0, lower = 0, val;
	// No need to create matrix!
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> val;

			if (i <= j)
				lower += val;

			if (i >= j)
				upper += val;
		}
	}
	cout << upper << "\n";
	cout << lower << "\n";

	return 0;
}

