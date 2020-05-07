#include<iostream>
using namespace std;

int main() {
	int arr[100][100];
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int r1, r2;
		cin >> r1 >> r2;
		r1--;
		r2--;

		bool is_smaller = true;
		for (int j = 0; j < m; ++j)
			is_smaller &= (arr[r1][j] < arr[r2][j]);

		if (is_smaller)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}

