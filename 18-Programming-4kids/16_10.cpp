#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

void print(set<string> &v) {
	for (string x : v)
		cout << x << " ";
	cout << "\n";
}

int main() {
	set<string> strSet;				// Sorted & unique
	strSet.insert("ziad");
	strSet.insert("mostafa");
	strSet.insert("mostafa");
	strSet.insert("mostafa");
	strSet.insert("ali");

	print(strSet);	// ali mostafa ziad

	if (strSet.count("mostafa"))
		cout << "YES\n";

	set<string>::iterator it = strSet.find("mostafa");
	//auto it = strSet.find("mostafa");		// or shorter using auto

	if (it != strSet.end())
		strSet.erase(it);

	print(strSet);	// ali ziad

	return 0;
}
