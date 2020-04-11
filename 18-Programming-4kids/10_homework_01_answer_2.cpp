// By Basel Bairkdar https://www.facebook.com/baselbairkdar

#include<iostream>
using namespace std;

int main() {
	// As values are 0-500, we can make array of 501 mark the last value in it
	// Then we answer the queries directly

	const int N = 500 + 1;
	int n, q, x, ans[N];

	for (int i = 0; i < N; i++)
		ans[i] = -1; /** at first the answer of any number is -1 **/

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		ans[x] = i;/** update the answer for x to be i **/
	}
	int num;
	cin >> q;
	while (q--) {
		cin >> num;
		cout << ans[num] << endl;
	}
	return 0;
}
