#include<iostream>
using namespace std;

int main() {
	int arr[100][100];
	int rows, cols;

	cin >> rows >> cols;

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			cin >> arr[i][j];

	int i = 0, j = 0, sum = 0;
	int di[3] { 1, 0, 1 };
	int dj[3] { 0, 1, 1 };

	while (i < rows && j < cols) {
		sum += arr[i][j];

		int next_val, best_i = -1, best_j = -1;

		for (int d = 0; d < 3; ++d) {
			int ni = i + di[d], nj = j + dj[d];

			if (ni < rows && nj < cols) {
				if (best_i == -1 || next_val < arr[ni][nj])
					next_val = arr[ni][nj], best_i = ni, best_j = nj;
			}
		}
		if (best_i == -1)
			break;
		i = best_i, j = best_j;
	}
	cout << sum << "\n";

	return 0;
}
