#include <bits/stdc++.h>
using namespace std;

class DecoratedString: public string {
public:

	// inheriting the constructors from string
	using string::string;

	// using std::string::operator=;

	void decorate() {
		string str = *this;
		str = "<<[[" + str + "]]>>";

		//*this = str;
		this->assign(str);

		// You can't just use: *this = str;
		// as this is = assignment operator (later to study)
		// The default assignment operator = now is for DecoratedString not std::string
		// If you want it possible, add also using std::string::operator=;
	}
};

int main() {
	DecoratedString str = "I am learning CS";

	str.decorate();
	cout << str << "\n";	// <<[[I am learning CS]]>>
	cout<<(  str == "<<[[I am learning CS]]>>"  );	// True
}
