#include<iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int digits = 0;

	while (num > 0) {
		digits += 1;
		num = num / 10;
	}
	cout<<digits;
	return 0;
}
