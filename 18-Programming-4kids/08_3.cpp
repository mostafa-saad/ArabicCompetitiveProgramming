#include<iostream>
using namespace std;

int main() {
	int x = 1;
	int sum = 0;

	while (x < 6)
	{
		sum += x;
		++x;
	}
	cout<<sum;

	return 0;
}
