#include<iostream>
#include<fstream>	// for ifstream and ofstream
using namespace std;

int main() {
	string path = "names.txt";
	fstream file_handler(path.c_str(), ios::in | ios::out | ios::app);

	if (file_handler.fail()) {
		cout << "Can't open the file\n";
		return 0;
	}
	string first, second;
	file_handler >> first >> second;

	cout << first << " " << second << "\n";

	file_handler.clear();	// if any internal errors, before writing

	file_handler << "\nibrahim\n";

	file_handler.close();

	return 0;
}
