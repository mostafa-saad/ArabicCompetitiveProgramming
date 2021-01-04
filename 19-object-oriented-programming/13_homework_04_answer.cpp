#include <bits/stdc++.h>
using namespace std;

#include "json.hpp"
using namespace json;

// Below: What we did with payments satisfies Dependency inversion principle
// High-level modules (wesite class) should not depend on low-level modules (PaypalPayment APIs).
// Both should depend on abstractions (e.g. IPayment).


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

class SquarePaymentAPI {
public:
	bool static WithDrawMoney(string JsonQuery) {
		//cout << JsonQuery << "\n";
		json::JSON obj = JSON::Load(JsonQuery);
		return true;
	}
};

/////////////////////
class IPayment {
public:
	virtual void SetUserInfo(string name, string address) = 0;
	virtual void SetCardInfo(string id, string expire_date, int ccv) = 0;
	virtual bool MakePayment(double money) = 0;
	virtual ~IPayment() {
	}
};

class PayPalPayment: public IPayment {
private:
	PayPalOnlinePaymentAPI paypal;
	PayPalCreditCard card;
public:
	virtual void SetUserInfo(string name, string address) {
		card.name = name;
		card.address = address;
	}
	virtual void SetCardInfo(string id, string expire_date, int ccv) {
		card.id = id;
		card.expire_date = expire_date;
		card.ccv = ccv;
	}
	virtual bool MakePayment(double money) {
		paypal.SetCardInfo(&card);
		return paypal.MakePayment(money);
	}
};

class StripePayment: public IPayment {
private:
	StripeCardInfo card;
	StripeUserInfo user;
public:
	virtual void SetUserInfo(string name, string address) {
		user.name = name;
		user.address = address;
	}
	virtual void SetCardInfo(string id, string expire_date, int ccv) {
		card.id = id;
		card.expire_date = expire_date;
	}
	virtual bool MakePayment(double money) {
		return StripePaymentAPI::WithDrawMoney(user, card, money);
	}
};

class SquarePayment: public IPayment {
private:
	string name;
	string address;
	string id;
	string expiry_date;
	int ccv;

public:
	virtual void SetUserInfo(string name_, string address_) {
		name = name_;
		address = address_;
	}
	virtual void SetCardInfo(string id_, string expiry_date_, int ccv_) {
		id = id_;
		expiry_date = expiry_date_;
		ccv = ccv_;
	}
	virtual bool MakePayment(double money) {
		// This now similar to Adapter pattern. We change format of interface to match another interface
		json::JSON obj;
		obj["user_info"] = json::Array(name, address);
		obj["card_info"]["ID"] = id;
		obj["card_info"]["DATE"] = expiry_date;
		obj["card_info"]["CCV"] = ccv;
		obj["money"] = money;

		ostringstream oss;
		oss << obj;
		string json_query = oss.str();

		return SquarePaymentAPI::WithDrawMoney(json_query);
	}
};


class PaymentFactory {
public:
	// In single place, gather all payments
	// In future a change happens here
	// Called Factory method design pattern
	static IPayment* GetPaymentHelper() {
		if (true)
			return new SquarePayment();
		else if (true)
			return new PayPalPayment();
		else
			return new StripePayment();
	}
};

//////////////////////////////

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
private:
	IPayment* payment;

public:
	Craigslist() {
		// Craigslist knows nothing about PayPal
		payment = PaymentFactory::GetPaymentHelper();
	}

	bool Pay(TransactionInfo info) {
		payment->SetUserInfo(info.name, info.address);
		payment->SetCardInfo(info.id, info.expire_date, info.ccv);
		return payment->MakePayment(info.required_money_amount);
	}
};


int main() {
	TransactionInfo info = { 20.5, "mostafa", "canada", "11-22-33-44", "09-2021", 333 };
	Craigslist site;
	site.Pay(info);

	return 0;
}
