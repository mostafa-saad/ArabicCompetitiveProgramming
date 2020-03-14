#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T > 0) {
		int num;
		cin >> num;

		int sum = 0;
		int start = 1;

		while (start <= num) {
			sum += start;
			start++;
		}
		--T;
		cout << "Sum from 1 to " << num << " = " << sum << "\n";
	}

	return 0;
}
