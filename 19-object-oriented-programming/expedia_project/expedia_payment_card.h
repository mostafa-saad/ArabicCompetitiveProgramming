/*
 * expedia_payment_card.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_PAYMENT_CARD_H_
#define EXPEDIA_PAYMENT_CARD_H_



class PaymentCard {
protected:
	string owner_name;
	string card_number;
	string expiry_date;
	int security_code;	// e.g. ccv
	// string type;		// e.g. Visa or MasterCard
public:
	const string& GetCardNumber() const {
		return card_number;
	}

	void SetCardNumber(const string& cardNumber) {
		card_number = cardNumber;
	}

	const string& GetExpiryDate() const {
		return expiry_date;
	}

	void SetExpiryDate(const string& expiryDate) {
		expiry_date = expiryDate;
	}

	const string& GetOwnerName() const {
		return owner_name;
	}

	void SetOwnerName(const string& ownerName) {
		owner_name = ownerName;
	}

	int GetSecurityCode() const {
		return security_code;
	}

	void SetSecurityCode(int securityCode) {
		security_code = securityCode;
	}

	virtual string ToString() const {
		ostringstream oss;
		oss << "Owner: " << owner_name << " Card number: " << card_number << " Expiry date: " << expiry_date;
		// security_code shouldn't be displayed! for security reasons.
		return oss.str();
	}

	virtual PaymentCard* Clone() const = 0;

	virtual ~PaymentCard() {
	}
};

class DebitCard: public PaymentCard {
protected:
	string billing_address;

public:
	const string& GetBillingAddress() const {
		return billing_address;
	}

	void SetBillingAddress(const string& billingAddress) {
		billing_address = billingAddress;
	}

	virtual PaymentCard* Clone() const override {
		return new DebitCard(*this);
	}

	virtual string ToString() const {
		ostringstream oss;
		oss << "[Debit Card]: " << PaymentCard::ToString() << " Billing Address: " << billing_address;
		return oss.str();
	}
};

class CreditCard: public PaymentCard {
protected:
	// Say we don't keep billing address
	// Although no attributes, but better have separate class to differentiate them if needed
public:
	virtual string ToString() const override {
		ostringstream oss;
		oss << "[Credit Card]: " << PaymentCard::ToString();
		return oss.str();
	}
	virtual PaymentCard* Clone() const override {
		return new CreditCard(*this);
	}
};


#endif /* EXPEDIA_PAYMENT_CARD_H_ */
