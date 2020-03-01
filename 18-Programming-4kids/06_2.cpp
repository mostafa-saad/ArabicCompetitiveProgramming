#include<iostream>
using namespace std;

int main() {
	int num;
	cin>>num;

	if (num == 10)
	{
		int x = 3;
		cout<<"10 is lucky number\n";
		cout<<"also "<<2*num + x<<"\n";
	}
	//cout<<x;	# not visible here!

	return 0;
}

