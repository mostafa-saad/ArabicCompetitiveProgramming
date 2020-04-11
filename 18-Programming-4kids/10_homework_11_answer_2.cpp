// By Ayman Salah https://www.facebook.com/ayman.salah.abdelaziz
#include <iostream>
using namespace std;

int main() {
	int a[200];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int result = 0;

	// for every index i in the array we consider it as the start of a subarry
	for (int i = 0; i < n; i++) {
		// adding one to result because any subarray of size one considered increasing
		// this subarray will include the value in index i
		result++;
		// trying expanding a subarray which starts with at index i and
		// if this subarray still increasing then we add one to our result
		// otherwise we should stop expanding this subarray
		for (int j = i + 1; j < n; j++) {
			// if the current value is greater than or equal the previous one
			// then it's increasing
			if (a[j] >= a[j - 1])
				result++;
			// otherwise stop
			else
				break;
		}
	}

	// printing the result
	cout << result << endl;

	return 0;
}

