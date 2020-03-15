/*
 */

#include<iostream>
using namespace std;

int main() {
	int num;
	char ch;

	cin>>num>>ch;

	while(num > 0)
	{
		cout<<ch;
		num -= 1;
	}

	return 0;
}

