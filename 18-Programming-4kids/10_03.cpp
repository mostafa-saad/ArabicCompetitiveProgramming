#include<iostream>
using namespace std;

int main() {
	const int size = 5;

	// Declare 5 positions of type integer
	int numbers[size];

	for (int i = 0; i < size; ++i)
		cin >> numbers[i];

	int minimum = numbers[0];
	for (int i = 1; i < size; ++i)
		if (minimum > numbers[i])
			minimum = numbers[i];

	cout << minimum;

	return 0;
}

