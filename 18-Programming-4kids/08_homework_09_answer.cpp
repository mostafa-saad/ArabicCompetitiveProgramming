#include<iostream>
using namespace std;

int main() {
	int N;

	cin >> N;

	int pos = 0;

	while (pos < N) {
		string str;
		cin>>str;

		// there are 8 different ways to make 2 letters no in lower/upper cases
		if (str == "no" || str == "No" || str == "nO" || str == "NO" ||
			str == "on" || str == "oN" || str == "On" || str == "ON")
			cout<<str<<" ";

		pos++;
	}
	return 0;
}

