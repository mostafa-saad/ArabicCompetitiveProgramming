#include<iostream>
using namespace std;

int main()
{
	// Declare variable in memory. Garbage value
	int number1;
	int number2;

	// Assign values (in memory(
	number1 = 30;
	number2 = 10;

	// Get values
	cout<<number1 + number2<<"\n";
	cout<<number1 - number2<<"\n";

	// Reassign value
	number1 = 50;
	cout<<"2n+1 = "<<number1 * 2 + 1<<"\n";

	return 0;
}
