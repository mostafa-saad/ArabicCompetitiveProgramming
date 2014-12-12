//============================================================================
// Name        : Calculator V2: Functions + Loops
// Author      : https://www.youtube.com/user/nobody123497
//============================================================================

#include <iostream>
using namespace std;

// use call by reference to update main
void read2Numbers(double &dNum1, double &dNum2)
{
	while(true)
	{
		dNum1 = dNum2 = 0;

		cout<<"Please Enter 2 numbers: ";
		cin>>dNum1>>dNum2;

		// Input Validation
		if (cin.fail())
		{
			cout<<"You should enter correct values\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
			break;
	}
}

int menu()
{
	int		iChoice = 0;

	cout<<"\nMenu Options:\n";
	cout<<"\tTo sum the numbers enter 1\n";
	cout<<"\tTo subtract the numbers enter 2\n";
	cout<<"\tTo multiply the numbers enter 3\n";
	cout<<"\tTo divide the numbers enter 4\n";
	cout<<"\tTo enter the 2 numbers again, enter 5\n";

	cout<<"\n\tEnter the choice: ";
	cin>>iChoice;

	// Input Validation
	if (cin.fail())	{
		cout<<"\t\tYou should enter correct value\n\n";
		cin.clear();
		cin.ignore(10000, '\n');
		return menu();	// we can have loop as reading 2 num
	}
	return iChoice;
}

bool sum(double dNum1, double dNum2, double &dResult)
{
	dResult = dNum1 + dNum2;
	return true;
}

bool sub(double dNum1, double dNum2, double &dResult)
{
	dResult = dNum1 - dNum2;
	return true;
}

bool mul(double dNum1, double dNum2, double &dResult)
{
	dResult = dNum1 * dNum2;
	return true;
}

bool div(double dNum1, double dNum2, double &dResult)
{
	if (dNum2 == 0.0)
	{
		cout<<"\t\tWe can't divide by zero. Retry other 2 numbers\n\n";
		return false;
	}
	else
		dResult = dNum1 / dNum2;
	return true;
}
void runCalculator()
{
	double		dNum1 = 0, dNum2 = 0, dResult = 0;
	int			iChoice = 0;
	bool		bFinished = false;

	while(!bFinished)
	{
		read2Numbers(dNum1, dNum2);
		iChoice = menu();

		if (iChoice == 5)	continue;	// try again from start

		if (iChoice == 1)
			bFinished = sum(dNum1, dNum2, dResult);
		else if (iChoice == 2)
			bFinished = sub(dNum1, dNum2, dResult);
		else if (iChoice == 3)
			bFinished = mul(dNum1, dNum2, dResult);
		else if (iChoice == 4)
			bFinished = div(dNum1, dNum2, dResult);

		if (bFinished)
			cout<<"\nResult of operation: "<<dResult<<"\n";
	}
}

int main()
{
	cout<<"\t\t\t\t*** Welcome to our Calculator V1 ***\n\n\n\n";

	runCalculator();

	return 0;
}
