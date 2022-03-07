#include <bits/stdc++.h>
using namespace std;

class Reservation {
public:
	virtual double TotalCost() const = 0;

	virtual Reservation* Clone() const = 0;

	virtual ~Reservation() {
	}
};

class FlightReservation: public Reservation {
private:
	// Some data

public:
	FlightReservation(string several_parms = "") {
	}

	virtual FlightReservation* Clone() const override {
		return new FlightReservation(*this);
	}

	virtual double TotalCost() const override {
		return 2000;
	}
};

class HotelReservation: public Reservation {
private:
	int price_per_night;
	int total_nights;

public:
	HotelReservation(int price_per_night, int total_nights) :
			price_per_night(price_per_night), total_nights(total_nights) {
	}

	virtual HotelReservation* Clone() const override {
		return new HotelReservation(*this);
	}

	virtual double TotalCost() const override {
		return price_per_night * total_nights;
	}
};

class ItineraryReservation: public Reservation {
protected:
	vector<Reservation*> reservations;	// As has pointers, we need copy constructor

public:
	ItineraryReservation() {
	}

	ItineraryReservation(const ItineraryReservation& another_reservation) {	// copy constructor
		for (const Reservation* reservation : another_reservation.GetReservations())
			AddReservation(*reservation);
	}

	void AddReservation(const Reservation& reservation) {
		reservations.push_back(reservation.Clone());
	}

	virtual double TotalCost() const {
		double cost = 0;

		for (const Reservation* reservation : reservations)
			cost += reservation->TotalCost();

		return cost;
	}

	~ItineraryReservation() {
		Clear();
	}

	const vector<Reservation*>& GetReservations() const {
		return reservations;
	}

	void Clear() {
		for (const Reservation* reservation : reservations)
			delete reservation;
		reservations.clear();
	}

	virtual Reservation* Clone() const override {
		return new ItineraryReservation(*this);
	}
};

ItineraryReservation Make_ititinary() {
	ItineraryReservation itinerary;

	itinerary.AddReservation(FlightReservation());
	itinerary.AddReservation(FlightReservation());
	itinerary.AddReservation(HotelReservation(50, 2));

	return itinerary;
}

int main() {
	ItineraryReservation itinerary = Make_ititinary();
	cout << itinerary.TotalCost();	// 4100 = 2000 + 2000 + 100

	return 0;
}

