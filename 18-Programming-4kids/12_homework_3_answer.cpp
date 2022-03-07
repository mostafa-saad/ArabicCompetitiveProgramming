#include<iostream>
using namespace std;

int main() {
	int arr[100][100];
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	//{ d, r,  u,  l, ul, dr, ur, dl };
	int di[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
	int dj[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool valid_mountain = true;	// if no neighbors, will remain true!

			// check the 8 neighbors using dir array
			for (int d = 0; d < 8 && valid_mountain; ++d) {
				int ni = i + di[d];
				int nj = j + dj[d];

				if (ni < 0 || nj >= n || nj < 0 || nj >= m)
					continue;	// outside borders

				valid_mountain &= (arr[i][j] > arr[ni][nj]);
			}

			if (valid_mountain)
				cout << i << " " << j << "\n";
		}
	}

	return 0;
}
/**
important test
1 1
1

answer
0 0
 */

