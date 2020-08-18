#include <bits/stdc++.h>
using namespace std;

class OurPrice {
private:
	int price;

	OurPrice(int price){
		SetPrice(price);
	}
public:
	int GetPrice() const {
		return price;
	}

	void SetPrice(int price) {
		if (price < 10)
			price = 0;
		this->price = price;
	}
};

int main() {
	return 0;
}


/*
Notice that SetPrice involves some checks and changes for the input parameter. The constructor forget that

One way to fix it, to do the same in the constructor. But this duplicate the code!
One fix is to call SetPrice from the constructor or move common code to a function

The tip: Be careful when your setter has more logic (verification, throw an exception, chance parameter's value)

===

Is it a good idea for a constructor to call other methods?

*/
