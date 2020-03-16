#include<iostream>
using namespace std;

int main() {

	double a1, a2, a3, a4, a5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;

	double avg1 = (a1+a2+a3+a4+a5) / 5.0;	// A
	double sum1 = (a1+a2+a3) / (a4+a5);		// B
	double first3_avg = (a1+a2+a3) / 3.0;
	double last2_avg = (a4+a5) / 2.0;
	double avg2 = first3_avg / last2_avg;	// C

	cout<<avg1<<"\n";
	cout<<sum1<<"\n";
	cout<<avg2<<"\n";

	cout<<sum1 * 2.0/3.0<<"\n";		// C = 2/3 B

	return 0;
}

