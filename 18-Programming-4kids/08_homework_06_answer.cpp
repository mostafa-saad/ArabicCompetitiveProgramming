

/*
 *
 * Test cases
 * Input: 7 11 101 21 201 31 602 78
 *
 * Output: 35.25 301.333
 */

#include<iostream>
using namespace std;

int main() {
	int N;

	cin >> N;

	// Use doubles to: 1) allow any values 2) get average correctly
	double even_sum = 0, odd_sum = 0;
	int even_count = 0, odd_count = 0;

	int cnt = 1;
	while (cnt <= N) {
		double value;
		cin >> value;

		if (cnt % 2 == 0)	// even position
			even_sum += value, even_count++;
		else				// odd position
			odd_sum += value, odd_count++;

		cnt++;
	}

	cout <<odd_sum / odd_count << " " << even_sum / even_count << "\n";

	return 0;
}

