#include<iostream>
using namespace std;

int main() {
	int n, numbers[200];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];

	int idx1 = -1, idx2 = -1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (idx1 == -1)
				idx1 = i, idx2 = j;
			else if (numbers[idx1] + numbers[idx2] <
					 numbers[i] + numbers[j])
				idx1 = i, idx2 = j;
		}
	}
	cout<<numbers[idx1]<<" "<<numbers[idx2];

	return 0;
}

