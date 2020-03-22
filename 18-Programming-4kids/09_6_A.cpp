#include<iostream>
using namespace std;

int main() {
	int n, m, sum;

	cin >> n >> m >> sum;

	int cnt = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (i + j == sum)
				cnt++;


	cout << cnt << "\n";

	return 0;
}

