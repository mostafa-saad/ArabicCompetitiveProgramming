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


	return 0;
}
