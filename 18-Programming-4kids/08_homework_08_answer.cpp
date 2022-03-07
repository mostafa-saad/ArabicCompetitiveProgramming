#include<iostream>
using namespace std;

int main() {
	int N, result = 0;

	cin >> N;

	int cnt = 0;
	int current_number = 0;

	while (cnt < N) {
		if (current_number % 3 == 0 && current_number % 4 != 0) {
			cout << current_number << " ";
			cnt++;
		}
		current_number++;
	}
	return 0;
}

