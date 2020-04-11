#include <iostream>
using namespace std;

int main() {

	int n;
	int a[1000];
	int difference[1000*2+1];	// maximum 2000 values with shift 1000

	// mark the difference as never appeared
	for (int i = 0; i < 2001; ++i)
		difference[i] = 99999;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int maxSubarrayLength1 = 0;
	int maxSubarrayStartIndex1 = -1;
	int maxSubarrayEndIndex1 = -1;

	int added = 0;

	difference[0+1000] = -1;	// difference 0 appears before the array (-1)

	for (int i = 0; i < n; i++)
	{
		if(a[i] == 1)
			added += 1;
		else
			added -= 1;

		int shift = added + 1000;	// shift to make sure positive

		if(difference[shift] == 99999)
			difference[shift] = i;	// first time for such accumulated difference to appear
		else {
			int subarrayLength = i - difference[shift];

			if (subarrayLength > maxSubarrayLength1) {
				maxSubarrayLength1 = subarrayLength;
				maxSubarrayStartIndex1 = difference[shift]+1;
				maxSubarrayEndIndex1 = i;
			}
		}
	}

	if (maxSubarrayLength1 == 0)
		cout << "NOT FOUND" << endl;
	else {
		cout << maxSubarrayLength1 << endl;
		for (int i = maxSubarrayStartIndex1; i <= maxSubarrayEndIndex1; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	// By adding 0 as -1 values, each group of equal ones and zeros
	// is actually sub-array of sum zero


	return 0;
}
