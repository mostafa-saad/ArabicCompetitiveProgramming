#include<iostream>
using namespace std;

int main() {
	int num1, num2, num3;

	cin >> num1 >> num2 >> num3;

	int answer = num1;

	if (answer > num2)
		answer = num2;

	if (answer > num3)
		answer = num3;

	cout << answer << "\n";

	return 0;
}

