#include<iostream>
using namespace std;

int main() {
	const int size = 5;

	// Declare 5 positions of type integer
	int numbers[size] = {10, 2, 7, 5, 3};


	numbers[0] = 9;
	numbers[2] *= 3;
	numbers[4]++;

	cout<<numbers[4];

	return 0;
}
