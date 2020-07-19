#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v)
{
	vector<int>::iterator it;

	it = v.begin();

	while (it != v.end() ) {
		cout<<*it<<" ";
		++it;
	}
	// No value at v.end()
	cout<<"\n";
}

int main() {
	vector<int> v(5);

	for (int i = 0; i < (int)v.size(); ++i)
		v[i] = i;

	print(v);

	v.erase(v.begin() + 3);			// remove v[3]
	print(v);

	v.insert(v.begin() + 1, 17);	// insert before v[1]
	print(v);

	return 0;
}
