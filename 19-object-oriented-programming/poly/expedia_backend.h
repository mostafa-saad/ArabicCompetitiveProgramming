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
		flights_managers = FlightsFactory::GetFlighsManagers();
		payment_helper = PaymentFactory::GetPaymentHelper();
		hotels_managers = HotelsFactory::GetManagers();
	}
	vector<Flight> FindFlights(const FlightRequest &request) {
		vector<Flight> flights;

		for (IFlighsManager* manager : flights_managers) {
			manager->SetFlightRequest(request);
			vector<Flight> more_flights = manager->SearchFlights();

			flights.insert(flights.end(), more_flights.begin(), more_flights.end());
		}
		return flights;
	}

	vector<HotelRoom> FindHotels(const HotelRequest &request) {
		vector<HotelRoom> rooms;

		for (IHotelsManager* manager : hotels_managers) {
			manager->SetHotelRequest(request);
			vector<HotelRoom> more_rooms = manager->SearchHotelRooms();

			rooms.insert(rooms.end(), more_rooms.begin(), more_rooms.end());
		}
		return rooms;
	}

	bool ChargeCost(double cost, PaymentCard &payment_card) {
		// Every time you have to do dynamic case: think twice if there is more elegant way to remove that?
		// As with every new code change, you have to come and change it

		CreditCard* creditCard = nullptr;
		DebitCard* debitCard = nullptr;

		if ((creditCard = static_cast<CreditCard*>(&payment_card)))
			payment_helper->SetUserInfo(payment_card.GetOwnerName(), "");
		else if ((debitCard = static_cast<DebitCard*>(&payment_card))) {
			payment_helper->SetUserInfo(payment_card.GetOwnerName(), debitCard->GetBillingAddress());
		}
		payment_helper->SetCardInfo(payment_card.GetCardNumber(), payment_card.GetExpiryDate(), payment_card.GetSecurityCode());

		bool payment_status = payment_helper->MakePayment(cost);

		if (!payment_status)
			return false;	// Don't reserve this flight

		return true;
	}
};



#endif /* EXPEDIA_BACKEND_H_ */
