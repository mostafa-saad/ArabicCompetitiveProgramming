#include <bits/stdc++.h>
using namespace std;


class Employee {
private:
	string name;

public:
	Employee(string name) :
			name(name) {
		cout<<"Constructor: "<<name<<"\n";
	}
	~Employee() {
		cout<<"Destructor: "<<name<<"\n";
	}
};

int main() {
	static Employee belal("Belal");
	Employee most("Mostafa");
	if (true)
		Employee("Mona");
	static Employee Asmaa("Asmaa");

	return 0;
}







/*
Constructor: Belal
Constructor: Mostafa
Constructor: Mona
Destructor: Mona
Constructor: Asmaa
Destructor: Mostafa
Destructor: Asmaa
Destructor: Belal

Constructor's call are the easy part.

For destructor, Think in the object's life time
- Static object ends ONLY with the end of the program.
- So every static member ends only after complete end of program life time
	- If there are more than static, destruction in reverse order

- For local objects, once its scope is done
	- Notice mona's scope ends after the if, but most ends after return 0

*/
