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

	while (i < rows && j < cols) {
		sum += arr[i][j];

		int next_val, best_i = -1, best_j = -1;

		// is right ok position?
		if (j + 1 < cols)
			next_val = arr[i][j + 1], best_i = i, best_j = j + 1;

		// is down ok position?
		if (i + 1 < rows) {
			if (best_i == -1 || next_val < arr[i + 1][j])
				next_val = arr[i + 1][j], best_i = i + 1, best_j = j;
		}
		// is diagonal ok position?
		if (i + 1 < rows && j + 1 < cols) {
			if (best_i == -1 || next_val < arr[i + 1][j + 1])
				next_val = arr[i + 1][j + 1], best_i = i + 1, best_j = j + 1;
		}

		if (best_i == -1)
			break;
		i = best_i, j = best_j;
	}
	cout << sum << "\n";

	return 0;
}

