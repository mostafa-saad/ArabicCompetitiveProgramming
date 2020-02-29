#include<iostream>
using namespace std;

int main() {
	int num1 = 7, num2 = 231, num3;

	// Swap operation in 3 steps using num3 as temporary storage
	// 1) put num2 value in num3
	num3 = num2;	// now num3 is 231

	// put num1 in num2
	num2 = num1;		// now num2 is 7

	// get the temp value in num3 in num1
	num1 = num3;

	cout<<num1<<" "<<num2<<endl;	// 231 7

	// if hard? maybe watch https://www.youtube.com/watch?v=A7li4rrkS54


	return 0;
}
