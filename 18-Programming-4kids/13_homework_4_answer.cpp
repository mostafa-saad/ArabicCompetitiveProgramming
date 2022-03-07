#include<iostream>
using namespace std;

int read_array(int arr[]) {
	int len;
	cin >> len;
	for (int i = 0; i < len; ++i)
		cin >> arr[i];

	return len;
}

bool is_palindrome(int arr[], int n) {
	int st = 0, en = n - 1;
	while (st < en) {
		if (arr[st] != arr[en])
			return false;
		st++, en--;
	}
	return true;
}

int main() {
	int arr[100];
	int len = read_array(arr);
	cout<<is_palindrome(arr, len);
	return 0;
}
