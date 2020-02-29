#include<iostream>
using namespace std;

int main() {
	/*
	 * We know we will read 8 numbers
	 * 	The first number is the first odd
	 * 	The third number is the second odd
	 * 	The fifth number is the their odd
	 * 	The seventh number is the forth odd
	 *
	 * Same logic for even numbers
	 *
	 * The key: good naming variables and read them in right order
	 */
	int even1, even2, even3, even4;
	int odd1, odd2, odd3, odd4;

	cin>>odd1>>even1;
	cin>>odd2>>even2;
	cin>>odd3>>even3;
	cin>>odd4>>even4;

	int even_sum = even1 + even2 + even3 + even4;
	int odd_sum = odd1 + odd2 + odd3 + odd4;

	cout<<even_sum<<" "<<odd_sum<<"\n";

	return 0;
}

/*
Try inputs

11 2 7 9 12 -8 3 -1

 */
