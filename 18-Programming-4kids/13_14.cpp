#include<iostream>
using namespace std;

int sum_array(int arr[], int len) {
	int sum = 0;
	for (int i = 0; i < len; ++i)
		sum += arr[i];
	return sum;
}

int main() {
	int arr[6] = {1, 2, 3, 4, 5, 6};
	cout << sum_array(arr, 3) << "\n";
	cout << sum_array(arr, 6) << "\n";

	return 0;
}
