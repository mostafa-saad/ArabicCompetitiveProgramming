#include<iostream>
using namespace std;

int main() {
	// 8/3 = 2.6666666666666 ..... 6666
	double num = 8/3.0;

	cout<<num<<"\n";

	int res = (int)num;	// casting
	cout<<res<<"\n";

	char ch = 'a';
	int ch_value = (int)ch;

	cout<<ch_value<<"\n";

	cout<<(int)'a'<<" "<<(int)'z'<<"\n";
	cout<<(int)'A'<<" "<<(int)'Z'<<"\n";


	return 0;
}

