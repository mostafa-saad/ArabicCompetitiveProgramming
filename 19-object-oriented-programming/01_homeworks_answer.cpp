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




const int MAX = 500;
string employee_first_name[MAX];
string employee_middle_name[MAX];
string employee_last_name[MAX];
int employee_age[MAX];
double employee_salary[MAX];




struct BankCustomer {
	string name;
	string address;
	string mobile;
	string birth_of_date;
	int rectangle_width;
	string favourite_movie;
	string favourite_color;
	string favourite_actor;
	string favourite_car_model;
	string favourite_food;


	// Potential several functions related to birth date
};
/*
 * Code Review comments from Mostafa to Mohamed:
 * 1- rectangle_width;
 * I can't think in a reason why this attribute is used. Probably copy/paste mistake. Be careful or clarify.
 *
 * 2- string favourite_*
 * What is the value of all of these favourite attributes. In OOP, only "relevant" attributes are used
 * Although a person could have favourite_food, but this is not relevant in our context (banking app)
 *
 * 3- string birth_of_date;
 * As you know, we may have several functions related to birth date
 * This data type(string) will be painful. Every time we will have to extract day/month/year
 * You better add 3 integers for them.
 * Even better, use the struct Date that we already built for the birth date. The class has a lot of functionalities
 * This way we reduce the 'RESPONSIBILITY' of our class. RESUABILITY is critical concern in OO.
 * Think in more COMPOSITION of other objects (e.g. BankCustomer has a Date, where Date is another object).
 */

int main() {

	return 0;
}
