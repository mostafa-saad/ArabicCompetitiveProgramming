/*
 * expedia_common.h
 *
 *  Created on: Sep 22, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_COMMON_RESERVATION_H_
#define EXPEDIA_COMMON_RESERVATION_H_

class Reservation {
public:
	virtual Reservation* Clone() const = 0;

	virtual double TotalCost() const = 0;

	virtual string ToString() const = 0;

	virtual ~Reservation() {
	}
};

// You might think: let's create class HotelFlight reservation
// What in future about reservations for cars? Cruise? whatever?
// Think in future: can we handle things in generic way?

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

	virtual string ToString() const override {
		ostringstream oss;

		oss <<"**********************************************\n";
		oss << "Itinerary of " << reservations.size() << " sub-reservations\n";

		for (const Reservation* reservation : reservations)
			oss << reservation->ToString() << "\n";

		oss << "Total Itinerary cost: " << TotalCost() << "\n";
		oss <<"**********************************************\n";
		return oss.str();
	}

	virtual Reservation* Clone() const override {
		return new ItineraryReservation(*this);
	}
};

class ReservationsSet: public ItineraryReservation {
public:
	// We need another class that act like set of different reservations (not Itinerary)
	// This has same functionalities as ItineraryReservation
	// It is much better to have its own class, even empty class
	// Then code is more semantic + we can do future changes easily

	using ItineraryReservation::ItineraryReservation;	// use its copy constructor

	virtual Reservation* Clone() const {
		return new ReservationsSet(*this);
	}
};

#endif /* EXPEDIA_COMMON_RESERVATION_H_ */
