// By Ayman Salah https://www.facebook.com/ayman.salah.abdelaziz
#include <iostream>
using namespace std;

int main() {
	int a[200];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int result = 0;

	// For every possible array length
	// Try all possible sub-arrays
	// Verify and sum
	for (int len = 1; len <= n; ++len) {
		for (int st = 0; st < n - len + 1; ++st) {
			bool is_ok = true;
			for (int k = 1; k < len && is_ok; ++k) {
				if (a[st + k] <= a[st + k - 1])
					is_ok = false;
			}
			result += is_ok;
		}
	}

	cout << result << endl;

	return 0;
}
