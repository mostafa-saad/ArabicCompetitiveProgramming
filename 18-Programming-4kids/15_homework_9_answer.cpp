#include<iostream>
using namespace std;

void right_max_v1(int arr[], int len, int start_pos = 0) {
	if (start_pos == len - 1)
		return;

	right_max_v1(arr, len, start_pos + 1);
	arr[start_pos] = max(arr[start_pos], arr[start_pos + 1]);
}

void right_max_v2(int arr[], int len) {
	if (len == 1)
		return;

	right_max_v2(arr + 1, len-1);	// arr+1 is the a new array shifted. E.g. { 1, 8, 2, 10, 3 } => {8, 2, 10, 3 }
	arr[0] = max(arr[0], arr[1]);	// Then we only need to think about arr (0)
}

int main() {
	int arr[] = { 1, 8, 2, 10, 3 };

	right_max_v1(arr, 5);

	for (int i = 0; i < 5; ++i) {
		cout<<arr[i]<<" ";
	}

	return 0;
}

