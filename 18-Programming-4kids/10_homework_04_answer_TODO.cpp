// By Basel Bairkdar https://www.facebook.com/baselbairkdar
#include<iostream>
using namespace std;

int main() {
	/**
	 we will put the first three elements from the array
	 in a new array called mn which will store the minimum
	 three values so far.

	 now we will iterate over the input array and see
	 if the current element is less than the maximum element
	 in array mn, if so we will make change.
	 **/
	const int N = 200;
	int n, a[N], mn[3], mx;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i < 3) {
			mx = max(mx, a[i]);
			mn[i] = a[i];
		}
	}
	for (int i = 3; i < n; i++) {
		if (a[i] < mx) {
			for (int j = 0; j < 3; j++) {
				if (mn[j] == mx) {
					mn[j] = a[i];
					break;
				}
			}
			// update mx value
			for (int j = 0; j < 3; j++) {
				if (mn[j] > mx) {
					mx = mn[j];
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << mn[i] << ((i == n - 1) ? "\n" : " ");
	}
	return 0;
}
