// By Ayman Salah https://www.facebook.com/ayman.salah.abdelaziz
#include <iostream>
using namespace std;


int main() {

	// declaring a variable to store size of the array
	int n;
	// declaring the array itself to store the values in it
	// notice here the maximum size of any given array in the problem will be 200
	int a[200];

	// reading size of the array
	cin >> n;

	// reading array values
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// intializing the result with zero
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
