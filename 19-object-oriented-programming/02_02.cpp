#include <bits/stdc++.h>
using namespace std;

class Quote {
private:
	int internal;

	string GetQuote() {
		return "The way to get started is to "
				"quit talking and begin doing";
	}

public:
	int external;

	Quote() {
		internal = 3, external = 7;
	}

	void print() {
		cout<<GetQuote()<<"\n";
	}
};

int main() {
	Quote q;

	cout<<q.external<<"\n";
	q.print();

	//q.internal;		// can't access
	//q.GetQuote();		// can't call


	return 0;
}
