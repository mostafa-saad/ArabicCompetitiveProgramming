#include<iostream>
using namespace std;

double arr_average(double arr[], int len) {
	if (len == 1)
		return arr[0];

	double sub_result = arr_average(arr, len - 1);
	// Now this was average of len-1. So sum / (len-1)
	sub_result = sub_result * (len-1);

	return (sub_result + arr[len - 1] ) / len;
}

int main() {
	double arr[] = { 1, 8, 2, 10, 3 };

	cout << arr_average(arr, 5);

	return 0;
}

