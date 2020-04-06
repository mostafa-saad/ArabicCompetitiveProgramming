#include<iostream>
using namespace std;

int main() {
	int numbers[5] = { 1, 2, 3, 4, 5 };

	char name1[5] = { 'H', 'a', 'n', 'i' };	// 5 not 4
	char name2[5] = "Hani";

	string name3 = "Hani";

	cout << name1 << "\n";
	cout << name2 << "\n";
	cout << name3 << "\n";

	return 0;
}

