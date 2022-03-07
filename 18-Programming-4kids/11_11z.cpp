#include<iostream>
using namespace std;

// Practice count words


int main() {
	string line;
	getline(cin, line);

	int cnt = 0;

	int pos = 0;

	while (pos < line.size())
	{
		// skip characters: space and tabs
		while (pos < line.size() && (line[pos] == ' ' || line[pos] == '\t'))
			pos++;

		if (pos >= line.size())
			break;	// ended

		// we have a new word. let's read it
		cnt++;
		while (pos < line.size() && !(line[pos] == ' ' || line[pos] == '\t'))
			pos++;
	}
	cout<<cnt<<"\n";

	// The other way works with files only. Ignore for now

	return 0;
}
