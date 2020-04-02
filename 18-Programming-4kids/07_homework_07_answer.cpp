#include<iostream>
using namespace std;

int main() {
	int x, start, end, cnt = 0;

	cin>>x;

	//Read start and end, then see if X is between them or not, 3 times
	cin>>start>>end;
	cnt += (start <= x && x <= end);

	cin>>start>>end;
	cnt += (start <= x && x <= end);

	cin>>start>>end;
	cnt += (start <= x && x <= end);

	cout<<cnt<<"\n";

	return 0;
}

