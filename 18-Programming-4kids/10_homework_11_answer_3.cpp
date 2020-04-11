#include <iostream>
using namespace std;

int main() {
	int a[200];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int result = 0;
	int len = 1;
	
	
	// Let say we have increasing sequence of length 4. It means we have 4*5/2 valid sub arrays
	// So, find each maximual sub-sequence and add them using n*(n+1) /2
	// Or just increment with length each time we extend it
	

	// We will count sequence of length  > 1. Later add +n
	for (int i = 1; i < n; i++) {
		// Keep expand len as long as the sub-array is increasing. 
		if (a[i - 1] <= a[i]) {
			result += len;
			++len;
		} else
			len = 1;
	}

	cout << result + n << endl;

	return 0;
}

