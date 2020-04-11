#include <iostream>
using namespace std;

int main() {
	const int N = 200;
	int n, k;
	int arr[N];

	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int max_sum = 0;	// First k values
	int min_index = 0;
	for (int i = 0; i < k; i++)
		max_sum += arr[i];

	int sum = max_sum;
	for (int i = k; i < n; i++) {
		// remove element before and add current element. Now they are new k elements
		sum = sum - arr[i - k] + arr[i];

		if (sum > max_sum) {
			max_sum = sum;
			min_index = i - (k - 1);
		}
	}
	cout << min_index << " " << min_index + k - 1 << " " << max_sum << "\n";

}

