#include<iostream>
using namespace std;

int main() {
	string name = "Hany";

	int sz = name.size();	// called function/method
	cout << sz << "\n";	// 4

	cout << name << "\n";

	for (int i = 0; i < sz; ++i)
		cout << name[i];	// internally array

	return 0;
}

