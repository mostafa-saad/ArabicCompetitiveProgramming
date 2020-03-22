#include<iostream>
using namespace std;

int main() {
	int n = 10;

	for (int a = 0, b = 1, c = -1, cnt = 0; cnt < n;
			++cnt, c = a + b, a = b, b = c)
		cout << a << " ";

	return 0;
}

