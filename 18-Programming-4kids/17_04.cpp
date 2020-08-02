#include<iostream>
#include<fstream>	// for ifstream and ofstream
using namespace std;

int main() {
	ifstream fin("read_file.txt");

	if(fin.fail())
	{
		cout<<"Can't open the file\n";
		return 0;
	}
	int x, y;
	fin >> x >> y;
	fin.close();

	ofstream fout("my_output.txt");

	if(fout.fail())
	{
		cout<<"Can't open the output file\n";
		return 0;
	}

	fout << x + y;
	fout.close();



	// you can read from several files

	return 0;
}
