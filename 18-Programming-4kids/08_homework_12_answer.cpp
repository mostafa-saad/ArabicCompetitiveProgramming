#include<iostream>
using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	int cnt_n = 1;

	while (cnt_n <= n) {
		int cnt_m = 1;

		while (cnt_m <= m) {
			cout << cnt_n << " x " << cnt_m << " = " << cnt_n * cnt_m << "\n";
			cnt_m++;
		}
		cnt_n++;
	}

	return 0;
}

