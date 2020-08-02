#include<iostream>
#include<fstream>	// for ifstream and ofstream
using namespace std;

int main() {
	string path = "names.txt";
	fstream file_handler(path.c_str());

	if (file_handler.fail()) {
		cout << "Can't open the file\n";
		return 0;
	}
	string line;

	while (getline(file_handler, line))
		cout << line << "\n";

	file_handler.close();

	return 0;
}
