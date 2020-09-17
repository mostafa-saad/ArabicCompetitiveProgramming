#include <bits/stdc++.h>
using namespace std;

// Below: What we did with flights and payments satisfy Dependency inversion principle
// High-level modules (expedia.com) should not depend on low-level modules (AirCandaAirlines/PaypalPayment APIs).
// Both should depend on abstractions (e.g. IFlighsFinder and IPayment).

////////////////////////////////
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
	bool static WithDrawMoney(StripeUserInfo user, StripeCardInfo card, double money) {
		return true;
	}
};

////////////////////////////////

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

////////////////////////////////

class AirCanadaFlight {
public:
	double price;
	string date_time_from;
	string date_time_to;
};

class AirCanadaOnlineAPI {
public:
	static vector<AirCanadaFlight> GetFlights(string from, string from_date, string to, string to_date, int adults, int childern) {
		return vector<AirCanadaFlight>();
	}
};

class TurkishFlight {
public:
	double cost;
	string datetime_from;
	string datetime_to;
};

class TurkishAirlinesOnlineAPI {
public:
	void SetFromToInfo(string datetime_from, string from, string datetime_to, string to) {
	}
	void SetPassengersInfo(int infants, int childern, int adults) {
	}
	vector<TurkishFlight> GetAvailableFlights() {
		return vector<TurkishFlight>();
	}
};

////////////////////////////////

class Flight {
public:
	double total_cost;
	string date_time_from;
	string date_time_to;
};

class PassengerRequest {
public:
	string datetime_from;
	string from;
	string datetime_to;
	string to;
	int infants;
	int childern;
	int adults;

	string GetDatePartFrom() {
		return datetime_from;	// extract date only
	}

	string GetDatePartTo() {
		return datetime_to;	// extract date only
	}
};

class IFlighsFinder {
protected:
	PassengerRequest request;
public:
	virtual void SetPassengerRequest(const PassengerRequest &request_) {
		request = request_;
	}
	virtual vector<Flight> SearchFlights() = 0;
	virtual ~IFlighsFinder() {
	}
};

class AirCanadaFlighsFinder: public IFlighsFinder {
public:
	virtual vector<Flight> SearchFlights() {
		vector<AirCanadaFlight> flights_aircanada = AirCanadaOnlineAPI::GetFlights(request.from, request.GetDatePartFrom(), request.to, request.GetDatePartTo(), request.adults, request.childern);
		vector<Flight> flights;

		// convert
		for (auto & flight_aircanada : flights_aircanada) {
			Flight flight;
			flight.date_time_from = flight_aircanada.date_time_from;
			flight.date_time_to = flight_aircanada.date_time_to;
			flight.total_cost = flight_aircanada.price;

			flights.push_back(flight);
		}
		return flights;
	}
};

class TurkishFlighsFinder: public IFlighsFinder {
private:
	TurkishAirlinesOnlineAPI api;
public:
	virtual vector<Flight> SearchFlights() {
		api.SetFromToInfo(request.datetime_from, request.from, request.datetime_to, request.to);
		api.SetPassengersInfo(request.infants, request.childern, request.adults);

		vector<TurkishFlight> flights_turkey = api.GetAvailableFlights();
		vector<Flight> flights;

		// convert
		for (auto & flight_turkey : flights_turkey) {
			Flight flight;
			flight.date_time_from = flight_turkey.datetime_from;
			flight.date_time_to = flight_turkey.datetime_to;
			flight.total_cost = flight_turkey.cost;

			flights.push_back(flight);
		}
		return flights;
	}
};

////////////////////////////////

class Factory {
public:
	static vector<IFlighsFinder*> GetFlighsFinders() {
		vector<IFlighsFinder*> flights_finders;

		flights_finders.push_back(new TurkishFlighsFinder());
		flights_finders.push_back(new AirCanadaFlighsFinder());

		return flights_finders;
	}

	static IPayment* GetPaymentHelper() {
		if (true)
			return new PayPalPayment();
		else
			return new StripePayment();
	}
};

class Expedia {
private:
	vector<IFlighsFinder*> flights_finders;
	IPayment* payment_helper;
public:
	Expedia() {
		flights_finders = Factory::GetFlighsFinders();
		payment_helper = Factory::GetPaymentHelper();
	}
	vector<Flight> FindFlights(const PassengerRequest &request) {
		vector<Flight> flights;

		for (auto finder : flights_finders) {
			finder->SetPassengerRequest(request);
			vector<Flight> more_flights = finder->SearchFlights();

			flights.insert(flights.end(), more_flights.begin(), more_flights.end());	// append them
		}
		return flights;
	}

};



// As a project
// Add more flight classes + later operator overloading something + Simulators + logging
// Fawy project maybe with adapters + craigslist

int main() {

	return 0;
}

