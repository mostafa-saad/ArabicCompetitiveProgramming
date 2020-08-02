#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
	// Create a 3D array using vectors
	vector< vector<vector<int>>> v1;
	vector< vector<vector<int>>> v2(3, vector<vector<int>>(4, vector<int>(5, 100)));
	cout<<v2.size()<<" x "<<v2[0].size()<<" x "<<v2[0][0].size()<<"\n";	// 3 x 4 x 5 array

	for (int i = 0; i < v2.size(); ++i) {
		for (int j = 0; j < v2[0].size(); ++j) {
			for (int k = 0; k < v2[0][0].size(); ++k) {
				//cout<<v2[i][j][k]<<"\n";
			}
		}
	}

	// Create a 3D array using maps (+ whatever makes sense)
	map<int, map<int, map<int, int>> > mp;
	mp[10][20][-70] = 1;	// remember that map is very slow compare to 3d vector

	return 0;
}
