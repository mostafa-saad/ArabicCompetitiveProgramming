#include<iostream>
using namespace std;

int main() {
	int n, q, a[200];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> q;
	while (q--) {
		int num;
		cin >> num;

		int pos = -1;
		// search from the end
		for (int i = n-1; i >= 0; --i) {
			if (a[i] == num) {
				pos = i;
				break;
			}
		}
		cout << pos << "\n";
	}
	return 0;
}
