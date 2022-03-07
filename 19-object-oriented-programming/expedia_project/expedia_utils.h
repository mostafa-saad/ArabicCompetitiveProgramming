/*
 * expedia_utils.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_UTILS_H_
#define EXPEDIA_UTILS_H_

#include <bits/stdc++.h>
using namespace std;

////////////////////////// Utilities //////////////////////////
int ReadInt(int low, int high, bool cancel_choice_allowed = false) {	// Added parameter. Respect backward compatibility
	if (!cancel_choice_allowed)
		cout << "\nEnter number in range " << low << " - " << high << ": ";
	else
		cout << "\nEnter -1 to cancel or number in range " << low << " - " << high << ": ";

	int value;

	cin >> value;

	if (cancel_choice_allowed && value == -1)
		return value;

	if (low <= value && value <= high)
		return value;

	cout << "ERROR: invalid number...Try again\n";
	return ReadInt(low, high);
}

int ShowReadMenu(const vector<string> &choices, string header = "Menu") {	// Added parameter. Respect backward compatibility
	cout << "\n"<<header<<":\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
	return ReadInt(1, choices.size());
}

string GetCurrentTimeDate() {	// src: https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
	return ss.str();
}

#endif /* EXPEDIA_UTILS_H_ */
