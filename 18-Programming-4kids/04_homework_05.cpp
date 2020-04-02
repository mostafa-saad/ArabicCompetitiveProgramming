// Homework 5: Guess Program Output


#include<iostream>
using namespace std;

int main() {
	int num = 0;

	++num;
	num *= 10;
	num += 2;
	num = num * 10;
	num += 3;
	num = num * 10 + 4;
	num = 5 + num * 10;
	num = (num * 10 + 6) * 10 + 7;
	num = 5 * num * 2 * 1 + 5 + 2 + 1;

	cout<<num<<"\n";

	return 0;
}

