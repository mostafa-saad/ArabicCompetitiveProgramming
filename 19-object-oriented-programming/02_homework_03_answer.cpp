#include <bits/stdc++.h>
using namespace std;

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
