#include<iostream>
using namespace std;

int main() {
	int T;

	cin >> T;

	while (T > 0) {
		int N;
		cin >> N;

		int pos = 0;
		int result;

		while (pos < N) {
			int value;
			cin >> value;

			if (pos == 0)
				result = value;
			else if (result > value)
				result = value;

			pos++;
		}
		cout<<result<<"\n";

		--T;
	}

	return 0;
}

