#include<iostream>
using namespace std;

int main() {
	int n, numbers[200];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];

	int max_value = -1, max_repeat = -1;

	for (int i = 0; i < n; ++i)
	{
		// count how many times numbers[i] exists
		int repeat = 0;
		for (int j = 0; j < n; ++j)
			repeat += numbers[i] == numbers[j];

		if (max_repeat == -1 || max_repeat < repeat)
			max_repeat = repeat, max_value = numbers[i];
	}
	cout<<max_value<<" repeated "<<max_repeat<<" times";

	return 0;
}

