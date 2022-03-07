#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

void print(multiset<string> &v) {
	for (string x : v)
		cout << x << " ";
	cout << "\n";
}

int main() {
	multiset<string> strSet;				// Sorted & can repeat
	strSet.insert("ziad");
	strSet.insert("mostafa");
	strSet.insert("mostafa");
	strSet.insert("mostafa");
	strSet.insert("ali");

	print(strSet);	// ali mostafa mostafa mostafa ziad

	if (strSet.count("mostafa"))
		cout << "YES\n";

	multiset<string>::iterator it = strSet.find("mostafa");
	//auto it = strSet.find("mostafa");		// or shorter using auto

	if (it != strSet.end())
		strSet.erase(it);

	print(strSet);	// ali mostafa mostafa ziad

	return 0;
}
