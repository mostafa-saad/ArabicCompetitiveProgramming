/*
Homework 7: Swapping 3 numbers!


Same as previous, but on 3 numbers
Let say we have numbers a = 115, b = 20, c = 301
We wanna their final values to be: a = 20, b = 301, c = 115

*/

#include<iostream>
using namespace std;

int main() {
	int num1, num2, num3, temp = -1;

	// We can reduce a hard to easier problems
	// We solve it as separate swap operations

	cin>>num1>>num2>>num3;

	// swap num1, num2
	temp = num2;
	num2 = num1;
	num1 = temp;

	// swap num2, num3
	temp = num3;
	num3 = num2;
	num2 = temp;

	cout<<num1<<" "<<num2<<" "<<num3<<"\n";

	// Another solution by a student. Circulate them instead of direct 2 swaps
	cin>>num1>>num2>>num3;
	temp = num1;
	num1 = num2;
	num2 = num3;
	num3 = temp;

	cout<<num1<<" "<<num2<<" "<<num3<<"\n";


	return 0;
}
