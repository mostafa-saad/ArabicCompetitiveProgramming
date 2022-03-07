#include <bits/stdc++.h>
using namespace std;

class OurPrice {
private:
	int price;

public:
	OurPrice(int price){
		SetPrice(price);
	}
	
	int GetPrice() const {
		return price;
	}

	void SetPrice(int price) {
		if (price < 10)
			price = 0;
		this->price = price;
	}
	
	int SomeFun() {
		int price = 10;		
		int price2 = 20;
		int price3 = 20;

		// Is below price variable the local price with value 10 or the class class?
		// For a clear and maintainable code, avoid local variable names with same name as data members.
		return price + price2 + price3;
	}
};

int main() {
	return 0;
}


/*
OurPrice constructor should be public to use it

Notice that SetPrice involves some checks and changes for the input parameter. The constructor forget that

One way to fix it, to do the same in the constructor. But this duplicate the code!
One fix is to call SetPrice from the constructor or move common code to a function

The tip: Be careful when your setter has more logic (verification, throw an exception, change parameter's value)

===

A constructor can call other member functions of the class, such as set or get functions, 
but because the constructor is initializing the object, the data members may not yet be initialized. 
Using data members before they have been properly initialized can cause logic errors.
	C++ how to program (9.1)
*/
