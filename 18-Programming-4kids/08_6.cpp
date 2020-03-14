#include<iostream>
using namespace std;

int main() {
	int x, y;

	while (true) {
		cin >> x >> y;

		if (y == 0)
		{
			cout<<"Y is zero. Try other 2 numbers\n";
			continue;
		}
		cout << x / y << "\n";
	}
	cout<<"Bye\n";	// never reached

	return 0;
}
