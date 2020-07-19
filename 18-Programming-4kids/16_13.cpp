#include<iostream>
#include<map>
#include<vector>
using namespace std;

void print(vector< vector<int> > &v2d) {
	for (auto row : v2d)		// auto = vector<int<
	{
		for (auto col : row)	// auto = int
			cout<<col<<" ";
		cout<<"\n";
	}
}

int main() {
	// 2D Array using vector
	// (5, 7) 2d array with initial value 3
	vector< vector<int> > v2d(5, vector<int>(7, 3));

	cout<<v2d.size()<<"\n";		// 5
	cout<<v2d[0].size()<<"\n";	// 7

	v2d[1].push_back(5);
	v2d[1].push_back(6);
	v2d[4].erase(v2d[4].begin());

	print(v2d);
	return 0;
}
