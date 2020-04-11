#include <iostream>
using namespace std;

int main() {
	const int N = 200;
	int n, arr[N], k, min_index, max_sum = -10000000;

	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - k + 1; i++) {
		int sum = 0;
		for (int j = 0; j < k; ++j)
			sum += arr[i + j];

		if (sum > max_sum) {
			max_sum = sum;
			min_index = i;

		}
	}
	cout << min_index << " " << min_index + k - 1 << " " << max_sum << "\n";

}

