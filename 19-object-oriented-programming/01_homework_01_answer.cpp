#include <bits/stdc++.h>
using namespace std;

struct Date {
	int day;
	int month;
	int year;

	// Returns the length of the month represented by this date.
	int LengthOfMonth();

	// Returns the length of the year represented by this date.
	int LengthOfYear();

	// Returns a copy of this LocalDate with the specified number of days subtracted.
	Date MinusDays(int DaysToSubtract);
	Date MinusMonths(int MonthsToSubtract);
	Date MinusYears(int YearsToSubtract);
	Date MinusWeeks(int WeeksToSubtract);

	// Similarly, we can add Days. E.g. PlusDays(int DaysToAdd)

	// To allow flexible strings, user provide format,
	// e.g. yyyy.mm.dd returns (2014-07-26) and dd.mm returns (26-07)
	string ToString(string format);

	bool isEqual(Date d);
	bool isBefore(Date d);
	bool isAfter(Date d);

	bool IsLeapYear();	// google if don't know

	// These are just some methods. In reality, much more complex.
};

////////////////////////////////////////////////////////////

// We can describe time struct in 2 ways:
// Normal way: 3 integers for hours, minutes and seconds
// Another way is 1 variable only: total number of seconds. Which can be converted to the other way

// Although using 1 variable only saves memory, but it complicates the code.
// Clarity should be preferred than minor efficiency improvements


// In a debate with a college:
// Be open for different views (e.g, 2 ways for the data members)
// Defend your choices with logical reasons
// Also understand your college choices & reasons
// A lot of areas are just vague. We may not know which direction is definitely the right way
// Minor design concerns are not like big ones. System design is more risker than a class design
// Find someone with more experience to help you make decisions
// Or put time limit: discuss for an hour, then vote.
// Red flag if discussions are very lengthy with a few "action items"


int main() {

	return 0;
}
