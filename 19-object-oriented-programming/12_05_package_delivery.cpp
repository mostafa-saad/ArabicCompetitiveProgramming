#include <bits/stdc++.h>
using namespace std;

class Address {
private:
	string name;
	string address;
	string city;
public:
	const string& GetAddress() const {
		return address;
	}

	void SetAddress(const string& address) {
		this->address = address;
	}

	const string& GetCity() const {
		return city;
	}

	void SetCity(const string& city) {
		this->city = city;
	}

	const string& GetName() const {
		return name;
	}

	void SetName(const string& name) {
		this->name = name;
	}
};

class Package {
public:
	virtual double TotalCost() const = 0;
	virtual ~Package() {}
};

class StandardPackage : public Package {
private:
	Address sender_address;
	Address reciever_address;
	double weight_kg;
	double price_per_kg;

public:

	StandardPackage(const Address &sender_address, const Address &reciever_address, double weight_kg, double price_per_kg) :
			sender_address(sender_address), reciever_address(reciever_address), weight_kg(weight_kg), price_per_kg(price_per_kg) {
	}

	double TotalCost() const {
		return weight_kg * price_per_kg;
	}

	double GetPricePerKg() const {
		return price_per_kg;
	}

	void SetPricePerKg(double pricePerKg) {
		price_per_kg = pricePerKg;
	}

	const Address &GetRecieverAddress() const {
		return reciever_address;
	}

	void SetRecieverAddress(const Address &recieverAddress) {
		reciever_address = recieverAddress;
	}

	const Address & GetSenderAddress() const {
		return sender_address;
	}

	void SetSenderAddress(const Address &senderAddress) {
		sender_address = senderAddress;
	}

	double GetWeightKg() const {
		return weight_kg;
	}

	void SetWeightKg(double weightKg) {
		weight_kg = weightKg;
	}
};

class TwoDayPackage: public StandardPackage {
private:
	double fixed_fee;

public:
	TwoDayPackage(const Address &sender_address, const Address &reciever_address, double weight_kg, double price_per_kg, double fixed_fee) :
			StandardPackage(sender_address, reciever_address, weight_kg, price_per_kg), fixed_fee(fixed_fee) {
	}

	double TotalCost() const {
		return StandardPackage::TotalCost() + fixed_fee;
	}

	double GetFixedFee() const {
		return fixed_fee;
	}

	void SetFixedFee(double fixedFee) {
		fixed_fee = fixedFee;
	}
};

class HeavyPackage: public StandardPackage {
private:
	const double limit_kg = 100;
	double extra_price_per_kg;

public:
	HeavyPackage(const Address &sender_address, const Address &reciever_address, double weight_kg, double price_per_kg, double extra_price_per_kg) :
			StandardPackage(sender_address, reciever_address, weight_kg, price_per_kg), extra_price_per_kg(extra_price_per_kg) {
	}

	double TotalCost() const {
		double ret = StandardPackage::TotalCost();

		if (GetWeightKg() > limit_kg)
			ret += (GetWeightKg() - limit_kg) * extra_price_per_kg;
		return ret;
	}

	double GetExtraPricePerKg() const {
		return extra_price_per_kg;
	}

	void SetExtraPricePerKg(double extraPricePerKg) {
		extra_price_per_kg = extraPricePerKg;
	}
};

class PaymentCard {
private:
	string card_number;
	double expiry_date;
};

class CreditCard: public PaymentCard {
};

class DebitCard: public PaymentCard {
};

class Shipment {
private:
	vector<Package*> packages;
	PaymentCard* payement_card;

public:
	void AddPackage(StandardPackage* package) {
		packages.push_back(package);
	}

	void SetPaymentCard(PaymentCard* payement_card_) {
		payement_card = payement_card_;
	}

	double TotalCost() const {
		double total = 0;

		for (Package* package : packages)
			total += package->TotalCost();

		return total;
	}
};

class Customer {
private:
	vector<Shipment> shipments;
	vector<PaymentCard*> payment_cards;
public:

	void AddShipment() {

	}
};

int main() {

	return 0;
}

