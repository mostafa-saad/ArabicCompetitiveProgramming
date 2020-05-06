#include<iostream>
using namespace std;

int main() {
	int arr[100][100];

	int rows, cols;
	cin >> rows >> cols;

	for (int row = 0; row < rows; ++row)
		for (int col = 0; col < cols; ++col)
			cin >> arr[row][col];

	int max_i = 0, max_j = 0;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (arr[i][j] >= arr[max_i][max_j])
				max_i = i, max_j = j;
		}
	}
	cout << "Max value at position " << max_i << " " << max_j
			<< " with value = " << arr[max_i][max_j];
	return 0;
}

