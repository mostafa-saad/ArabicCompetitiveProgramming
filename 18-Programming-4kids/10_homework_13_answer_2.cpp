// By Ayman Salah https://www.facebook.com/ayman.salah.abdelaziz
#include <iostream>
using namespace std;

int main() {

	int n;
	int a[1000];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int maxSubarrayLength1 = 0;
	int maxSubarrayStartIndex1 = -1;
	int maxSubarrayEndIndex1 = -1;

	for (int start = 0; start < n; start++) {
		int zerosCount = 0;
		int onesCount = 0;

		// While expanding a sub-array just check if it is 0 or 1

		for (int end = start; end < n; end++) {
			if (a[end] == 0)
				zerosCount++;
			else if (a[end] == 1)
				onesCount++;

			if (zerosCount == onesCount) {
				int subarrayLength = end - start + 1;
				if (subarrayLength > maxSubarrayLength1) {
					maxSubarrayLength1 = subarrayLength;
					maxSubarrayStartIndex1 = start;
					maxSubarrayEndIndex1 = end;
				}
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


	return 0;
}
