#include <bits/stdc++.h>
using namespace std;

class Time {
private:
	// Put on separate lines for code clarity
	int hours;
	int minutes;
	int seconds;

public:
	Time(int hours, int minutes, int seconds) {
		// There is member function doing the same task
		// Avoid code duplication
		SetTime(hours, minutes, seconds);
	}
	void SetTime(int hours, int minutes, int seconds) {
		// Put on separate lines for code clarity
		// Still there is a missing point her.
		// We better use setters as they validate/change input
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
		// Code duplication!
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
	void SetHours(int hours) {
		// Be careful from missing verifications. This is important for "data-integrity"
		if (hours < 0)
			hours = 0;
		this->hours = hours;
	}
	int GetMinutes() {
		return minutes;
	}
	void SetMinutes(int minutes) {
		if (minutes < 0)
			minutes = 0;
		this->minutes = minutes;
	}
	int GetSeconds() {
		return seconds;
	}
	void SetSeconds(int seconds) {
		if (seconds < 0)
			seconds = 0;
		this->seconds = seconds;
	}
};

int main() {
	// This will print wrongly. E.g. every 60 second should be added as a minute. Every 60 minutes should be added as an hour
	Time t(0, 120, 120);
	t.PrintHHMMSS();	// proper printing: 2:2:0
	return 0;
}
