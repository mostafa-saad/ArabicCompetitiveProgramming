#include<iostream>
using namespace std;

int main() {

 cout<<"-If it shows 1, it's odd.\n \n";

    int num1;
    cin>>num1;
    
	cout<<(num1%2==1)<<"\n";
    
	cout<<(num1%10==1||num1%10==3||num1%10==5||num1%10==7||num1%10==9)<<"\n";
    
	double num1_double=num1;
        cout<<(num1_double/2==num1/2+.5)<<"\n";


	return 0;
}

