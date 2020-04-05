/*
 Homework 2: Create logic!

 Write a program that reads 3 integers about the class room
 Number of boys (nb), number of girls (ng), number of teachers (nt)

 Prepare and print a boolean variable for these cases:
	 nb greater than 25
	 ng less than or equal to 30
	 nb > 20 and nt > 2 or ng > 30 and nt > 4
	 Either nb < 60 or ng < 70
	 Neither nb >= 60 nor ng >= 70
	 nb is 10 more students than ng
	 Difference between nb and ng is more than 10 or nt > 5
	 Either nb is 10 more students than ng or ng is 15 more students than nb
 */

#include<iostream>
using namespace std;

int main() {
	int nb, ng, nt;
	cin >> nb >> ng >> nt;

	// nb greater than 25
	cout << (nb > 25) << "\n";

	// ng less than or equal to 30
	cout << (ng <= 30) << "\n";

	// nb > 20 and nt > 2 or ng > 30 and nt > 4
	cout << (nb > 20 && nt > 2 || ng > 30 && nt > 4) << "\n";

	// Either nb < 60 or ng < 70
	cout << (nb < 60 || ng < 70) << "\n";

	// Neither nb >= 60 nor ng >= 70
	cout << (  !(nb >= 60) && !(ng >= 70) ) << "\n";

	// nb is 10 more students than ng
	cout << (nb == ng + 10) << "\n";

	// Difference between nb and ng is more than 10 or nt > 5
	cout << (nb - ng > 10 || nt > 5) << "\n";

	// Either nb is 10 more students than ng or ng is 15 more students than nb
	cout << (nb == ng + 10 || ng == nb + 15) << "\n";

	return 0;
}

