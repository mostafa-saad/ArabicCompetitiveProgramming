#include<iostream>
#include<stack>
using namespace std;

void print(stack<string> &s) {
	cout << "Stack elements: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}
int main() {
	stack<string> s;
	s.push("ibrahim");
	s.push("saad");
	s.push("mostafa");

	print(s);	// mostafa saad ibrahim
	return 0;
}
