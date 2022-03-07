#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int main() {
	cout<<abs(-2)<<"\n";				// 2
	cout<<fabs(-2.4)<<"\n";				// 2.4
	cout<<ceil(2.4)<<"\n";				// 3
	cout<<floor(2.4)<<"\n";				// 2
	cout<<round(2.4)<<"\n";				// 2
	cout<<round(2.5)<<"\n";				// 3
	cout<<round(2.6)<<"\n";				// 3
	cout<<round(-2.6)<<"\n";			// -3
	cout<<round(-2.4)<<"\n";			// -2
	cout<<ceil(-2.4)<<"\n";				// -2	** TRICKY
	cout<<floor(-2.4)<<"\n";			// -3	** TRICKY
	cout<<sqrt(16)<<"\n";				// 4

	cout<<isalpha('A')<<"\n";			// 1024 = true
	cout<<isalpha('#')<<"\n";			// 0
	cout<<isdigit('3')<<"\n";			// 1 = true
	cout<<isdigit('A')<<"\n";			// 0
	cout<<isupper('A')<<"\n";			// 256 = true
	cout<<isupper('a')<<"\n";			// 0
	cout<<(char)tolower('X')<<"\n";		// x
	cout<<(char)toupper('x')<<"\n";		// X

	cout<<max(5, 9)<<"\n";				// 9
	cout<<pow(2, 4)<<"\n";				// 16
	cout<<pow(2, 4.1)<<"\n";			// 17.1484
	cout<<log2(16)<<"\n";				// 4
	cout<<log10(1000)<<"\n";			// 3

	cout<<(double)rand() / RAND_MAX<<"\n";	// 0.840188

	return 0;
}

