#include <bits/stdc++.h>
using namespace std;

// PayPalCreditCard and PayPalOnlinePaymentAPI are NOT our code. They are Paypal API.
// We have to use them to be able to call PayPal service


class PayPalCreditCard {
public:
	string name;
	string address;
	string id;
	string expire_date;
	int ccv;
};

class PayPalOnlinePaymentAPI {
public:
	void SetCardInfo(const PayPalCreditCard* const card) {
	}
	bool MakePayment(double money) {
		return true;
	}
};

class StripeUserInfo {
public:
	string name;
	string address;
};

class StripeCardInfo {
public:
	string id;
	string expire_date;
};

class StripePaymentAPI {
public:
	bool static WithDrawMoney(StripeUserInfo user,
							  StripeCardInfo card,
							  double money) {
		return true;
	}
};

class TransactionInfo {
public:
	double required_money_amount;
	string name;
	string address;
	string id;
	string expire_date;
	int ccv;
};

class Craigslist {
	public:
	bool Pay(TransactionInfo) {
		//TODO: generic (no nothing about Paypal)
	}
};


int main()
{
	return 0;
}
