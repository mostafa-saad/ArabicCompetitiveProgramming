#include<iostream>
using namespace std;

int main() {

	// Array of names - each name is sequence of letters!
	string names[5] = {"Mostafa Saad", "Never Ever", "Hello world"};

	for (int i = 0; i < 5; ++i)
		cout<<names[i]<<"\n";

	return 0;
}

