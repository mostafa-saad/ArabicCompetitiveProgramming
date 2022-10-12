#include<iostream>
using namespace std;

int main() {

	int num;
	cin >> num;

	// Is even using %2
	bool is_even1 = (num % 2 == 0);

	// is even using /2
	// one line solution:
	// **Hint** You don't need to cast 'num' to from 'int' to 'double' like "(double)num", 
	// by default if you divide it as an integer / 2.0 (which is double) 
	// C++ will convert num to 'double' and return 'double'
	bool is_even_2 = (num / 2.0 - num / 2) == 0;  
	
	// multiple lines solution:	
	//double by2 = (double) num / 2.0;// this is either X.0 or X.5  (try 10, 11)
	//by2 = by2 - (int) by2;// Remove X. This is now either 0 (for even) or 0.5 (for odd)
	//bool is_even2 = by2 == 0;

	// is even using %10
	int last_digit = num % 10;	// even last digit is 0, 2, 4, 6, 8
	bool is_even3 = last_digit == 0 || last_digit == 2 || last_digit == 4 || last_digit == 6 || last_digit == 8;

	return 0;
}

