#include<iostream>
using namespace std;

int main() {
	bool is_prime[100][100] = { 0 };
	int n, m, val;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> val;

			// let's compute is prime once NOT with every query. Also no need for main array
			if (val <= 1)
				continue;

			is_prime[i][j] = 1;
			for (int k = 2; k < val; ++k) {
				if (val % k == 0) {
					is_prime[i][j] = 0;
					break;
				}
			}
		}

	int q, si, sj, rs, cls;
	cin >> q;

	while (q--) {
		cin >> si >> sj >> rs >> cls;
		int cnt = 0;

		for (int i = si; i <= si + rs - 1; ++i)
			for (int j = sj; j <= sj + cls - 1; ++j)
				cnt += is_prime[i][j];

		cout << cnt << "\n";
	}

	return 0;
}
/**

 3 4
 8 16 9 52
 3 15 27 6
 14 25 29 10

 output
 8 3 14
 16 15 25
 9 27 29
 52 6 10


 */
