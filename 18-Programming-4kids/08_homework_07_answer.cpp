#include<iostream>
using namespace std;

int main() {
	int N, result = 0;

	cin >> N;

	int cnt = 0;

	while (cnt <= N)
	{
		if (cnt % 8 == 0 || cnt % 3 == 0 && cnt % 4 == 0)
			cout<<cnt<<" ";

		cnt ++;
	}




	return 0;
}

