#include <bits/stdc++.h>
using namespace std;

/*
struct DateTime {
	int day;
	int month;
	int year;
	int hours;
	int minutes;
	int seconds;

	// Constructor
	DateTime(int day, int month, int year,
			int hours, int minutes, int seconds) {
	}



	// A bunch of Time functions
	// ...
};
*/


// The problem with above class it is responsible for 2 things
// Date and all its complications
// Time and all its complications
// Always focus a struct on a specific functionality (single responsibility)
// Then, each struct is easier to code
// Easy to give different developers different tasks

struct Date {
	int day;
	int month;
	int year;

	// A bunch of Data functions
	// ...
};

struct Time {
	int hours;
	int minutes;
	int seconds;

	// A bunch of Time functions
	// ...
};

struct DateTime {
	Date date;
	Time time;

	// Constructor
	DateTime(Date date, Time time) {

	}
};

// Design seperate Date & time structs
// Datetime is "composed" of Date and Time



int main() {

	return 0;
}
