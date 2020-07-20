#include<iostream>
#include<vector>
#include<algorithm>		// sort algo
using namespace std;

void print(vector<int> &v)
{
	for (int x : v)
		cout<<x<<" ";
	cout<<"\n";
}

int main() {
	vector<int> v(5);

	for (int i = 0; i < (int)v.size(); ++i)
		v[i] = 10 - i;

	print(v);	// 10 9 8 7 6

	reverse(v.begin(), v.end());
	print(v);	// 6 7 8 9 10

	v.clear();
	print(v);



	return 0;
}
