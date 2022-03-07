#include<iostream>
#include<cstdlib>
using namespace std;

int add(int a, int b)
{
	return a+b;
}

int main() {
	cout << add(2, 3) << "\n";
	cout << add(2, 3.5) << "\n";

	return 0;
}
