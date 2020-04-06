#include<iostream>
using namespace std;

int main() {
	char ch1 = 'A';
	int ch_value = ch1;

	cout<<ch_value<<"\n";
	cout<<(int)'A'<<"\n";
	cout<<(int)'B'<<"\n";
	cout<<(int)'C'<<"\n";
	cout<<(int)'Z'<<"\n";
	cout<<(int)'A' + 26 - 1<<"\n";

	char ch2 = 90;
	cout<<ch2<<"\n";

	cout<<"***\n";

	cout<<(int)'a'<<"\n";
	cout<<(int)'b'<<"\n";
	cout<<(int)'c'<<"\n";
	cout<<(int)'z'<<"\n";
	cout<<(int)'a' + 26 - 1<<"\n";

	cout<<('A' < 'a')<<"\n";
	return 0;
}

