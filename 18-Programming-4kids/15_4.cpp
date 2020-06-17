#include<iostream>
using namespace std;

void print_triangle(int levels) {
	if (levels == 0)
		return;

	for (int i = 0; i < levels; ++i)
		cout << "*";
	cout << "\n";

	print_triangle(levels - 1);
}

int main() {
	print_triangle(5);
	return 0;
}

