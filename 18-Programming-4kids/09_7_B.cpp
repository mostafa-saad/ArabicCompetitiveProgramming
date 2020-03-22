#include<iostream>
using namespace std;

int main() {
	int n, m, w;

	cin >> n >> m >> w;

	int cnt = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int k = i + j;

			if (1 <= k && k <= w)
				cnt += w - k + 1;
	}

cout << cnt << "\n";

return 0;
}

