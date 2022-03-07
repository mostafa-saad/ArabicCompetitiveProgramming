#include <bits/stdc++.h>
using namespace std;

class Time {
private:
	int hours;
	int minutes;
	int seconds;

public:
	Time(int hours, int minutes, int seconds) {
		SetTime(hours, minutes, seconds);
	}
	void SetTime(int hours, int minutes, int seconds) {
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	int GetTotalSeconds() {
		return hours * 60 * 60 + minutes * 60 + seconds;
	}
	int GetTotalMinutes() {
		return hours * 60 + minutes;
	}
	void PrintHHMMSS() {
		cout<<ToSring(":")<<"\n";
	}
	string ToSring(string seperator = "-") {
		ostringstream oss;
		oss << hours << seperator << minutes << seperator << seconds;
		return oss.str();
	}
	int GetHours() {
		return hours;
	}
	Time& SetHours(int hours) {
		if (hours < 0)
			hours = 0;
		this->hours = hours;

		return *this;
	}
	int GetMinutes() {
		return minutes;
	}
	Time& SetMinutes(int minutes) {
		if (minutes < 0)
			minutes = 0;
		this->minutes = minutes;

		return *this;
	}
	int GetSeconds() {
		return seconds;
	}
	Time& SetSeconds(int seconds) {
		if (seconds < 0)
			seconds = 0;
		this->seconds = seconds;

		return *this;
	}
};

/*
what does it mean to do
	1) t.SetHours(5).Something?
	.Something is a function, then it needs object
	then t.SetHours(5) must return object of type time NOT void

	So we need to return object from these setters

	2) Now each object has pointer to itself this
		*this is the object
		We can return this but there is a problem
		It will be a copy, so NOT same
		This means we are modifying some temporary object NOT t itself!

	To solve that, return the object by reference: Time&T

	So overall
	Time& SomeSetter
		return *this



Q: Was it possible / More OOP to add const to return?:

	const Time& SetMinutes(int minutes)

 */

int main() {

	Time t(3, 1, 2);
	t.PrintHHMMSS();	// 3:1:2

	t.SetHours(5).SetMinutes(45).SetSeconds(13);
	t.PrintHHMMSS();	// 5:45:13

	return 0;
}
