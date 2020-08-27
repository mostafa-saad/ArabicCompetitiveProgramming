#include <bits/stdc++.h>
using namespace std;

class Time {
private:
	int total_seconds;

public:
	Time(int hours, int minutes, int seconds) {
		// Delegation: give another object/function the task to do it for you
		SetTime(hours, minutes, seconds);
	}
	void SetTime(int hours, int minutes, int seconds) {
		total_seconds = 0;
		SetHours(hours);
		SetMinutes(minutes);
		SetSeconds(seconds);
	}
	int GetTotalSeconds() {
		return total_seconds;
	}
	int GetTotalMinutes() {
		return GetHours() * 60 + GetMinutes();
	}
	void PrintHHMMSS() {
		cout << ToSring(":") << "\n";
	}
	string ToSring(string seperator = "-") {
		ostringstream oss;
		oss << GetHours() << seperator << GetMinutes() << seperator << GetSeconds();
		return oss.str();
	}
	int GetHours() {
		return total_seconds / (60 * 60);
	}
	void SetHours(int hours) {
		if (hours < 0)
			hours = 0;
		total_seconds += (hours - GetHours()) * 60 * 60;

	}
	int GetMinutes() {
		return (total_seconds % (60 * 60)) / 60;
	}
	void SetMinutes(int minutes) {
		if (minutes < 0)
			minutes = 0;
		total_seconds += (minutes - GetMinutes()) * 60;
	}
	int GetSeconds() {
		return total_seconds % 60;
	}
	void SetSeconds(int seconds) {
		if (seconds < 0)
			seconds = 0;
		total_seconds += (seconds - GetSeconds());
	}
};


// In previous code, all functions use directly the 3 integers
// It might be a good practice to depend on the available setters and getters
// Imagine a real Time class with 20 functions that use minutes, which now doesn't exist
// If they all use GetMinutes, no one of them will be changed
// Be careful with data members that might change or keep depending on setters/getters
// As you see, we could even provide setters & getters for variables that doesn't exist

// Code "flexibility" is important

int main() {
	Time t(0, 0, 0);
	t.SetMinutes(1);
	t.SetSeconds(60);
	t.SetHours(2);
	cout << t.GetTotalSeconds();
	return 0;
}
