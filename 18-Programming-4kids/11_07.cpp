#include<iostream>
using namespace std;

int main() {

	char name1[5];
	name1[0] = 'H';
	name1[1] = '\0';
	name1[2] = 'n';
	name1[3] = 'i';
	name1[4] = '\0';	// Null character

	cout << name1 << "\n";

	return 0;
}

