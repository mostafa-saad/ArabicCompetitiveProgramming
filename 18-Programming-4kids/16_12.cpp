#include<iostream>
#include<map>
#include<vector>
using namespace std;

void print(map<string, int> &mp) {
	// You could iterate on map and set normally like vector. Never to change keys while iterating
	for (pair<string, int> item: mp)
		cout << item.first<<"-"<<item.second << " | ";
	cout << "\n";
}

int main() {
	map<string, int> mp;	// Array with index not integer
	mp["Mostafa"] = 10;
	mp["Saad"] = 20;

	print(mp);	// Mostafa-10 | Saad-20 |

	map<char, vector<int> > my_data;

	vector<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);

	my_data['A'] = x;
	cout<<my_data['A'].size()<<"\n";	// 3

	return 0;
}
