#include<iostream>
using namespace std;

int main() {
	int x, y;
	x = 3, y = 5;

	bool result = (x > y);
	cout << result << "\n";

	result = (x < y);
	cout << result << "\n";

	cout << !result << "\n";
	cout << !(x < y) << "\n";

	return 0;
}
