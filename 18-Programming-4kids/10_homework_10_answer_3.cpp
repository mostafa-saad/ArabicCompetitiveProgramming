// By Amr Fahim https://www.facebook.com/amrfahim2020
// Homework 10 solution

#include <iostream>
using namespace std;

int main() {
	const int N = 200;
	int n, arr[N] = {0}, k, min_index, max_sum = -10000000;

	cin >> k >> n;
	// Note that we deal with 1-base array
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		// Cumulative sum for the array to get sum of subarray without nested loop
		// Each element of the array carries the sum of all previous elements
		arr[i] += arr[i - 1];
	}

	for (int i = k; i <= n; i++) {
		if (arr[i] - arr[i - k] > max_sum) {
			max_sum = arr[i] - arr[i - k];
			min_index = i - k + 1;

		}
	}
	cout << min_index-1 << " " << min_index + k -2<< " " << max_sum << "\n";

}

