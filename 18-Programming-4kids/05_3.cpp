#include<iostream>
using namespace std;

int main() {
	string name1 = "ali", name2 = "ali mostafa";
	string name3 = "ziad", name4 = "ali", name5 = "ALI";

	cout<<(name1 < name2) <<"\n";
	cout<<(name1 > name3) <<"\n";
	cout<<(name1 != name4) <<"\n";
	cout<<(name1 == name4) <<"\n";

	cout<<(name1 == name5) <<"\n";
	cout<<(name1 > name5) <<"\n";

	return 0;
}

