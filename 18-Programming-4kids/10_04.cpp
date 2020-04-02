#include<iostream>
using namespace std;

int main() {
	int n, numbers[200];	// max expected size

	cin>>n;
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];

	int maximum_idx = 0;
	for (int i = 1; i < n; ++i)
		if (numbers[maximum_idx] < numbers[i])
			maximum_idx = i;

	int max1 = numbers[maximum_idx];
	numbers[maximum_idx] = -1000000;	// assume good value

	maximum_idx = 0;	// same code again
	for (int i = 1; i < n; ++i)
		if (numbers[maximum_idx] < numbers[i])
			maximum_idx = i;

	int max2 = numbers[maximum_idx];
	cout << max1 << " " << max2;
	return 0;
}

