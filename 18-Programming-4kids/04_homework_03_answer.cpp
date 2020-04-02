/*
https://web.archive.org/web/20170810175653/http://www.acmaast.com/problem.php?id=83

Given 8 space-separated integers, find the sum of those in even places and the sum of those in odd places.

Note: Even place means the 2nd, 4th, 6th or 8th numbers, while odd places are the 1st, 3rd, 5th and 7th numbers.

Example Input:
11 2 7 9 12 -8 3 -1

Example Output:
2 33

Example Explanation:
2 + 9 + (-8) + (-1) = 2
11 + 7 + 12 + 3 = 33
*/

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
