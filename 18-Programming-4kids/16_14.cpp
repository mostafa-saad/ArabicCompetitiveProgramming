#include <iostream>
#include <bits/stdc++.h>	// Covers all you need typically
using namespace std;

int main() {
	string test = "hi abc abc abc abc";

	cout << test.substr(3) << "\n";			// abc abc abc abc
	cout << test.substr(3, 5) << "\n";		// abc

	cout << test.find("abc") << "\n";		// 3

	// starting the search at 6th character
	cout << test.find("abc", 5) << "\n";	// 7

	cout << "Mostafa at: " << test.find("Mostafa") << "\n";	// 18446744073709551615
	cout << "Mostafa at: " << (int) test.find("Mostafa") << "\n";	// -1

	//Functions that searches for a CHARACTER from a given string
	cout << test.find_last_of("cab") << "\n";			// 17
	cout << test.find_first_of("aic") << "\n";			// 1
	cout << test.find_first_of("aic", 4) << "\n";		// 5
	cout << test.find_first_not_of("aic") << "\n";		// 0

	// replace from 4, 3 chars with x
	test.replace(4, 3, "x");
	cout<<test<<"\n";			// hi axabc abc abc

	return 0;
}
