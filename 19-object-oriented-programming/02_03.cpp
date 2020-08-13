#include <bits/stdc++.h>
using namespace std;

class Result {
	// Link, Short Summary, Rank
};

class Setting {
	// E.g. Start-End Date + Type (text/image/video)
};

class Google {
private:
	/*
	 * Huge amount of internal data & methods
	 * Huge amount of internal used classes
	 *
	 * User don't need to know about them
	 * User shouldn't access them!
	 */

public:
	vector<Result> Search(string query, Setting setting) {
		return vector<Result>();
	}
};

int main() {
	// User care with WHAT not HOW (and its details)
	Google engine;
	vector<Result> results =
			engine.Search("Resource for OOP", Setting());

	return 0;
}
