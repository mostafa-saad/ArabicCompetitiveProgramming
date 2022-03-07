#include<iostream>
using namespace std;

// start & end are indices

bool is_palindrome_v1(int arr[], int start, int end) {
	if (start >= end)
		return true;

	if(arr[start] != arr[end])
		return false;

	return is_palindrome_v1(arr, start+1, end-1);
}

bool is_palindrome_v2(int arr[], int end) {
	if (end <= 0)
		return true;

	if(arr[0] != arr[end])
		return false;

	return is_palindrome_v2(arr + 1, end-2);
}

int main() {
	int arr[] = { 1, 8, 2, 8, 1 };

	cout << is_palindrome_v1(arr, 0, 4)<<"\n";
	cout << is_palindrome_v2(arr, 4)<<"\n";

	return 0;
}

