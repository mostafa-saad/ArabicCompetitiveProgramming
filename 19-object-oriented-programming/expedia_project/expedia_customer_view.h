/*
 * expedia_customer_view.h
 *
 *  Created on: Sep 23, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_CUSTOMER_VIEW_H_
#define EXPEDIA_CUSTOMER_VIEW_H_

#include <bits/stdc++.h>
using namespace std;

#include "expedia_cusomter_mgr.h"

class CustomerView {
private:
	CustomerManager &customer_manager;
	const Customer& customer;
	ItineraryReservation current_itinerary;

	void ReadFlightRequest(FlightRequest &request) const{
		string str;
		int val;

		cout << "Enter From: ";
		cin >> str;
		request.SetFrom(str);

		cout << "Enter From Date (dd-mm-yy): ";
		cin >> str;
		request.SetDatetimeFrom(str);

		cout << "Enter To: ";
		cin >> str;
		request.SetTo(str);

		cout << "Enter To Date (dd-mm-yy): ";
		cin >> str;
		request.SetDatetimeTo(str);

		cout << "Enter # of adults children (5-16) and infants: ";
		cin >> val;
		request.SetAdults(val);
		cin >> val;
		request.SetChildren(val);
		cin >> val;
		request.SetInfants(val);
	}

	void ReadHotelRequest(HotelRequest &request) const{
		string str;
		int val;

		cout << "Enter From Date (dd-mm-yy): ";
		cin >> str;
		request.SetFromDate(str);

		cout << "Enter From Date (dd-mm-yy): ";
		cin >> str;
		request.SetToDate(str);

		cout << "Enter Country: ";
		cin >> str;
		request.SetCountry(str);

		cout << "Enter City: ";
		cin >> str;
		request.SetCity(str);

		cout << "Enter # of adults and children: ";
		cin >> val;
		request.SetAdults(val);
		cin >> val;
		request.SetChildren(val);
	}

	int ChooseFlight(const vector<Flight> &flights) const {
		if (flights.size() == 0) {
			cout << "No trips for this request info\n";
			return -1;
		}

		for (const Flight& flight : flights) {
			cout << flight.ToString() << "\n";
		}

		return ReadInt(1, flights.size(), true);
	}

	int ChooseRoom(const vector<HotelRoom> &rooms) const{
		if (rooms.size() == 0) {
			cout << "No trips for this request info\n";
			return -1;
		}

		for (const HotelRoom& room : rooms) {
			cout << room.ToString() << "\n";
		}

		return ReadInt(1, rooms.size(), true);
	}

	void AddFlight() {
		FlightRequest request;
		ReadFlightRequest(request);

		vector<Flight> flights = customer_manager.FindFlights(request);
		int flight_choice = ChooseFlight(flights);

		if (flight_choice == -1)
			return;

		Flight &flight = flights[flight_choice - 1];

		FlightReservation reservation(request, flight);
		current_itinerary.AddReservation(reservation);
	}

	void AddHotel() {
		HotelRequest request;
		ReadHotelRequest(request);

		vector<HotelRoom> rooms = customer_manager.FindHotels(request);
		int hotel_choice = ChooseRoom(rooms);

		if (hotel_choice == -1)
			return;

		HotelRoom &room = rooms[hotel_choice - 1];

		HotelReservation reservation(request, room);
		current_itinerary.AddReservation(reservation);
	}

	void PayItinerary() {
		// We can mark it const, but wrong, don't
		vector<string> payment_choices = customer_manager.GetPaymentChoices();
		int payment_chocie = ShowReadMenu(payment_choices, "Select a payment choice");
		PaymentCard* payment_card = customer.GetCards()[payment_chocie - 1];

		bool status = customer_manager.MakeReservation(current_itinerary, *payment_card);

		if (status) {
			cout << "Itinerary reserved\n";
		} else
			cout << "Failed to reserve the Itinerary\n";
	}

public:
	CustomerView(CustomerManager &customer_manager) :
			customer_manager(customer_manager), customer(*customer_manager.GetCustomer()) {
	}

	void Display() {
		cout << "\n\nHello " << customer.GetName() << " | User View\n";

		vector<string> menu;
		menu.push_back("View Profile");
		menu.push_back("Make Itinerary");
		menu.push_back("List my itineraries");
		menu.push_back("Logout");

		while (true) {
			int choice = ShowReadMenu(menu);
			if (choice == 1)
				ViewProfile();
			else if (choice == 2)
				MakeItinerary();
			else if (choice == 3)
				ListItineraries();
			else
				break;
		}
	}

	void ViewProfile() const {
		cout << "\n" << customer.ToString() << "\n";
	}

	void MakeItinerary() {
		vector<string> menu;
		menu.push_back("Add Flight");
		menu.push_back("Add Hotel");
		menu.push_back("Done");
		menu.push_back("Cancel");

		while (true) {
			int choice = ShowReadMenu(menu);
			if (choice == 1)
				AddFlight();
			else if (choice == 2)
				AddHotel();
			else if (choice == 3) {
				PayItinerary();
				current_itinerary.Clear();
				break;
			} else {
				current_itinerary.Clear();
				break;
			}
		}
	}
	void ListItineraries() const {
		vector<string> itineraries = customer_manager.GetItineraries();

		if (itineraries.size() == 0) {
			cout << "No itineraries so far!\n";
		}

		for (string& str : itineraries)
			cout << str << "\n";
	}
};

#endif /* EXPEDIA_CUSTOMER_VIEW_H_ */
