#include<iostream>
using namespace std;

int main() {
	int x = 5;
	int sum = 0;

	while (x >= 0)
	{
		sum += x;
		x--;
	}
	cout<<sum;

	return 0;
}
