#include<iostream>
using namespace std;

int main() {
	int n, numbers[200];	// max expected size

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];

	int max1, max2;
	if (numbers[0] >= numbers[1])
		max1 = numbers[0], max2 = numbers[1];
	else
		max1 = numbers[1], max2 = numbers[0];

	for (int i = 2; i < n; ++i)
		if (max1 <= numbers[i])
			max2 = max1, max1 = numbers[i];
		else if (max2 < numbers[i])
			max2 = numbers[i];

	cout << max1 << " " << max2;
	return 0;
}

