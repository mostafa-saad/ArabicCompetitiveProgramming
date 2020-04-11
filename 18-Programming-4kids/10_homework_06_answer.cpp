// By Amr Keleg https://www.facebook.com/amr.keleg

#include <iostream>
using namespace std;

int main() {
	// The size of the array should be larger than
	// the maximum value of N
	int arr[1000];

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// We need to compare the value at the left half
	// to those in the right half
	// The value at index (0) should be compared to the value at index (N-1)
	// Then the value at index (1) should be compared to the value at index (N-2)
	// So, clearly we need to increment the left index and decrement the right one
	// On reaching the index N/2, we are sure that we have compared all the elements
	// of both sides so we don't need to do anything and the array is palindrome
	for (int i = 0; i < N / 2; i++) {
		if (arr[i] != arr[N - 1 - i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
