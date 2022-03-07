#include <bits/stdc++.h>
using namespace std;

class Time {
private:
	int hours, minutes, seconds;

public:
	Time(int hours, int minutes, int seconds) :
			hours(hours), minutes(minutes), seconds(seconds) {
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
		cout << hours << ":" << minutes << ":" << seconds << "\n";
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
	Time t(0, 1, 1);
	t.PrintHHMMSS();
	return 0;
}
