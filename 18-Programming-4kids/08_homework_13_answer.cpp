#include<iostream>
using namespace std;

int main() {
	int T;

	cin >> T;

	/**
	 * We need 3 nested loops
	 * loop over test cases
	 * 	loop over reading numbers
	 * 	  loop to repeat the number K times (multiplication)
	 */

	while (T > 0) {
		int N;
		cin >> N;

		int cnt_N = 1;
		int sum = 0;
		while (cnt_N <= N) {
			int value = 0;
			cin >> value;

			int cnt_deep = cnt_N;
			int result = 1;

			while (cnt_deep > 0)
				result *= value, cnt_deep--;

			sum += result;
			cnt_N++;
		}
		cout<<sum<<"\n";

		T--;
	}

	return 0;
}

