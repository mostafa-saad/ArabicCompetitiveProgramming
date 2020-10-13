/*
 * expedia_backend.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_BACKEND_H_
#define EXPEDIA_BACKEND_H_

#include "expedia_payments_api.h"
#include "expedia_payment_card.h"
#include "expedia_flights_api.h"
#include "expedia_utils.h"
#include "expedia_user.h"
#include "expedia_hotels_api.h"

class ExpediaBackend {
private:
	vector<IFlighsManager*> flights_managers;
	IPayment* payment_helper;

	vector<IHotelsManager*> hotels_managers;

public:
	ExpediaBackend(const ExpediaBackend&) = delete;
	void operator=(const ExpediaBackend&) = delete;

	ExpediaBackend() {
		flights_managers = FlightsFactory::GetManagers();
		payment_helper = PaymentFactory::GetPaymentHelper();
		hotels_managers = HotelsFactory::GetManagers();
	}
	vector<Flight> FindFlights(const FlightRequest &request) const {
		vector<Flight> flights;

		for (IFlighsManager* manager : flights_managers) {
			manager->SetFlightRequest(request);
			vector<Flight> more_flights = manager->SearchFlights();

			flights.insert(flights.end(), more_flights.begin(), more_flights.end());
		}
		return flights;
	}

	vector<HotelRoom> FindHotels(const HotelRequest &request) const {
		vector<HotelRoom> rooms;

		for (IHotelsManager* manager : hotels_managers) {
			manager->SetHotelRequest(request);
			vector<HotelRoom> more_rooms = manager->SearchHotelRooms();

			rooms.insert(rooms.end(), more_rooms.begin(), more_rooms.end());
		}
		return rooms;
	}

	bool ChargeCost(double cost, PaymentCard &payment_card) const {
		// Every time you have to do dynamic case: think twice if there is more elegant way to remove that?
		// As with every new code change, you have to come and change it

		CreditCard* creditCard = nullptr;
		DebitCard* debitCard = nullptr;

		if ((creditCard = dynamic_cast<CreditCard*>(&payment_card)))
			payment_helper->SetUserInfo(payment_card.GetOwnerName(), "");
		else if ((debitCard = dynamic_cast<DebitCard*>(&payment_card))) {
			payment_helper->SetUserInfo(payment_card.GetOwnerName(), debitCard->GetBillingAddress());
		}
		payment_helper->SetCardInfo(payment_card.GetCardNumber(), payment_card.GetExpiryDate(), payment_card.GetSecurityCode());

		bool payment_status = payment_helper->MakePayment(cost);

		if (!payment_status)
			return false;	// Don't reserve this flight

		return true;
	}

	bool UnchargeCost(double cost, PaymentCard &payment_card) const {
		return true;
	}

	bool CancelReservation(const Reservation& reservation) {
		return true;
	}

	bool ConfirmReservation(const Reservation& reservation) {
		// We can think of factory of factories to maybe be able to make this generic
		// But let;s make your life easier at this stage

		FlightReservation* flight = nullptr;
		Reservation* reservationCpy = reservation.Clone();

		if ((flight = dynamic_cast<FlightReservation*>(reservationCpy))) {
			string name = flight->GetFlight().GetAirlineName();
			IFlighsManager* mgr = FlightsFactory::GetManager(name);

			if (mgr != nullptr && mgr->ReserveFlight(*flight))
				return true;

			return false;	// we shouldn't delete mgr pointer. In future, the factory should do so
		}

		HotelReservation* hotel = nullptr;
		if ((hotel = dynamic_cast<HotelReservation*>(reservationCpy))) {
			string name = hotel->GetRoom().GetHotelName();
			IHotelsManager* mgr = HotelsFactory::GetManager(name);

			if (mgr != nullptr && mgr->ReserveRoom(*hotel))
				return true;

			return false;	// we shouldn't delete mgr pointer. In future, the factory should do so
		}

		ItineraryReservation* itiniary = nullptr;
		if ((itiniary = dynamic_cast<ItineraryReservation*>(reservationCpy))) {
			vector<Reservation*> confirmed_reservations;

			for (Reservation* sub_reservation : itiniary->GetReservations()) {
				bool is_confirmed = ConfirmReservation(*sub_reservation);

				if (is_confirmed)
					confirmed_reservations.push_back(sub_reservation);
				else {
					// If failed to reserve, cancel all what is confirmed so far!
					for (Reservation* conf_reservation : confirmed_reservations)
						CancelReservation(*conf_reservation);
					return false;
				}
			}
		} else
			assert(false);

		// Intentional for education: there is memory leak
		// The above returns won't come here to remove this memory!
		// Always be sure you can return in middle of function or not. Better not if u have pointers
		delete reservationCpy;
		reservationCpy = nullptr;
		return true;
	}
};

#endif /* EXPEDIA_BACKEND_H_ */
