#include<iostream>
using namespace std;

void change(int a, int &b) {
	a++;
	b++;
}

void read(int x, int &y, string &str) {
	cin >> x >> y >> str;
}

int main() {
	int a = 1, b = 1;
	change(a, b);
	cout << a << " " << b << "\n";

	string name;
	read(a, b, name);
	cout << a << " " << b << " " << name << "\n";

	return 0;
}

