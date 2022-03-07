#include <bits/stdc++.h>
using namespace std;

void hello() {
	int i1 = 0;
	static int i2 = 0;

	cout<<i1<<" "<<i2<<"\n";
	i1 ++;
	i2 ++;
}

int main()
{
	hello();
	hello();
	hello();
	return 0;
}
