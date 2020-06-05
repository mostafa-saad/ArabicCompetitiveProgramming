#include<iostream>
using namespace std;

string reverse_str(const string & str)
{
	string ret = str;
	int st = 0, en = (int)str.size()-1;
	while(st < en) {
		// swap
		char tmp = ret[en];
		ret[en] = ret[st];
		ret[st] = tmp;

		st++, en--;
	}
	return ret;
}

int main() {
	cout<<reverse_str("")<<"\n";
	cout<<reverse_str("abcd")<<"\n";
	cout<<reverse_str("abcde")<<"\n";

	return 0;
}
