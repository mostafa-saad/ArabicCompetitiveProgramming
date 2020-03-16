#include<iostream>
using namespace std;

int main() {
	int num1 = 20;
	int num2 = num1 + 5;

	cout<<"num2 "<<num2<<"\n";

	num1 = num1 + 1;
	cout<<"num1 "<<num1<<"\n";

	num2 += 1;	// same as num2 = num2+1
	cout<<"num2 "<<num2<<"\n";

	num2++;		// same as num2 = num2+1
	cout<<"num2 "<<num2<<"\n";

	--num2;		// same as num2 = num2-1
	cout<<"num2 "<<num2<<"\n";

	num1 *= 2;	// same as num1 = num1 * 2
	cout<<"num1 "<<num1<<"\n";

	cout<<num1+num2<<"\n";

	num2 = num1-2;
	cout<<"num2 "<<num2<<"\n";

	num2 = num1-(-2);
	cout<<"num2 "<<num2<<"\n";

	return 0;
}

