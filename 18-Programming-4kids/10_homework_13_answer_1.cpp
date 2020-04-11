// By Ayman Salah https://www.facebook.com/ayman.salah.abdelaziz
#include <iostream>
using namespace std;

int main() {

	// declaring a variable to store size of the array
	int n;
	// declaring the array itself to store the values in it
	// notice here the maximum size of any given array in the problem will be 1000
	int a[1000];

	// reading size of the array
	cin >> n;

	// reading array values
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// we can solve this problem with more than one way

	// ======================================
	// let's start with the easist one

	// declaring a variable to store the length of the maximum subarray
	// that has zeros count equals ones count
	// intially we have an empty subarray with length 0
	int maxSubarrayLength = 0;

	// declaring a variable to store the start index of maximum subarray with our condition
	// intially we set this value with -1, that means we didn't find any subarray
	int maxSubarrayStartIndex = -1;

	// the same with the end index
	int maxSubarrayEndIndex = -1;

	// simply we try all start and end indices of subarrays
	for (int start = 0; start < n; start++) {
		for (int end = start; end < n; end++) {
			// intializing a variable to hold zeros count
			int zerosCount = 0;
			// intializing a variable to hold ones count
			int onesCount = 0;

			// another loop to count zeros and ones in subarray [start, end]
			for (int i = start; i <= end; i++) {
				// if value at index i equals one then add one to onesCount
				if (a[i] == 1)
					onesCount++;
				// if value at index i equals zero then add one to zerosCount
				else if (a[i] == 0)
					zerosCount++;
			}
			// checking if zeros count equals ones count or not
			if (zerosCount == onesCount) {
				// calculating length of current subarray
				int subarrayLength = end - start + 1;

				// checking if the length of this subarray is larger than the current maximum one or not
				if (subarrayLength > maxSubarrayLength) {
					// setting current max length with this value
					maxSubarrayLength = subarrayLength;
					// changing start and end index as well
					maxSubarrayStartIndex = start;
					maxSubarrayEndIndex = end;
				}

			}
		}
	}

	// checking if we found a subarray with this conditions or not
	if (maxSubarrayLength == 0)
		cout << "NOT FOUND" << endl;
	else {
		// a subarray is found,
		// printing it's length
		cout << maxSubarrayLength << endl;
		// printing it's values
		for (int i = maxSubarrayStartIndex; i <= maxSubarrayEndIndex; i++)
			cout << a[i] << " ";
		cout << endl;
	}

	return 0;
}
