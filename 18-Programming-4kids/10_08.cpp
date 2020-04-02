#include<iostream>
using namespace std;

int main() {
	int n, numbers[200];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];

	for (int i = 0; i < n/2; ++i) {
		int last = n - i - 1;
		// swap positions: i and last
		int temp = numbers[i];
		numbers[i] = numbers[last];
		numbers[last] = temp;
	}

	for (int i = 0; i < n; ++i)
		cout<<numbers[i]<<" ";
	return 0;
}

