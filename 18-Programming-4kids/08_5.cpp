#include<iostream>
using namespace std;

int main() {
	int x, y;

	while (true) {
		cin >> x >> y;

		if (y == 0)
		{
			cout<<"Y is zero!!\n";
			break;
		}
		cout << x / y << "\n";
	}
	cout<<"Bye\n";

	return 0;
}
