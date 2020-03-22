#include<iostream>
using namespace std;

int main() {
	int N, T, value;

	cin >> T;

	while (T--) {
		cin >> N;

		int sum = 0;
		for (int i = 0; i < N; ++i) {
			cin >> value;

			int result = 1;
			for (int j = 0; j < i + 1; ++j)
				result *= value;
			sum += result;
		}
		cout << sum << "\n";
	}

	return 0;
}

