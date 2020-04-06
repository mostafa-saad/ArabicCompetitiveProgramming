#include<iostream>
using namespace std;

int main() {
	char ch1 = 'D';

	if ('A' <= ch1 && ch1 <= 'Z') {
		cout << ch1 << " is an upper case\n";
		ch1 = ch1 - 'A' + 'a';
		cout << ch1 << " now is a lower case\n";
	} else if ('z' <= ch1 && ch1 <= 'z')
		cout << ch1 << " is already a lower case\n";
	else if ('0' <= ch1 && ch1 <= '9')
		cout << ch1 << " is a digit\n";
	else
		cout << ch1 << " is neither a digit nor a letter\n";

	return 0;
}

