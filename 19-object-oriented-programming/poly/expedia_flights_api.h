/*
 * expedia_flights_api.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_FLIGHTS_API_H_
#define EXPEDIA_FLIGHTS_API_H_

#include <bits/stdc++.h>
using namespace std;

#include "expedia_common_reservation.h"

class AirCanadaFlight {
public:
	double price;
	string date_time_from;
	string date_time_to;
};

class AirCanadaOnlineAPI {
public:
	static vector<AirCanadaFlight> GetFlights(string from, string from_date, string to, string to_date, int adults, int childern) {
		vector<AirCanadaFlight> flights;

		flights.push_back( { 200, "25-01-2022", "10-02-2022" });
		flights.push_back( { 250, "29-01-2022", "10-02-2022" });
		return flights;
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
		vector<TurkishFlight> flights;

		flights.push_back( { 300, "10-01-2022", "10-02-2022" });
		flights.push_back( { 320, "12-01-2022", "10-02-2022" });
		return flights;
	}
};

////////////////////////////////

class IFlighsManager;

class Flight {
private:
	double total_cost = 0;
	string date_time_from;
	string date_time_to;
	IFlighsManager* manager;	// IFlighsManager& manager; can't do so directly

public:
	Flight(IFlighsManager* manager) :
			manager(manager) {
	}

	string ToString() const {
		ostringstream oss;
		oss << "Cost: " << total_cost << " Departure Date " << date_time_from << " Arrival date " << date_time_to;
		return oss.str();
	}

	const string& GetDateTimeFrom() const {
		return date_time_from;
	}

	void SetDateTimeFrom(const string& dateTimeFrom) {
		date_time_from = dateTimeFrom;
	}

	const string& GetDateTimeTo() const {
		return date_time_to;
	}

	void SetDateTimeTo(const string& dateTimeTo) {
		date_time_to = dateTimeTo;
	}

	double GetTotalCost() const {
		return total_cost;
	}

	void SetTotalCost(double totalCost) {
		total_cost = totalCost;
	}

	const IFlighsManager* GetManager() const {
		return manager;
	}
};

class FlightRequest {
private:
	string datetime_from;
	string from;
	string datetime_to;
	string to;
	int infants;
	int childern;
	int adults;

public:
	string GetDatePartFrom() {
		return datetime_from;	// extract date only
	}

	string GetDatePartTo() {
		return datetime_to;	// extract date only
	}

	int GetAdults() const {
		return adults;
	}

	void SetAdults(int adults) {
		this->adults = adults;
	}

	int GetChildern() const {
		return childern;
	}

	void SetChildern(int childern) {
		this->childern = childern;
	}

	const string& GetDatetimeFrom() const {
		return datetime_from;
	}

	void SetDatetimeFrom(const string& datetimeFrom) {
		datetime_from = datetimeFrom;
	}

	const string& GetDatetimeTo() const {
		return datetime_to;
	}

	void SetDatetimeTo(const string& datetimeTo) {
		datetime_to = datetimeTo;
	}

	const string& GetFrom() const {
		return from;
	}

	void SetFrom(const string& from) {
		this->from = from;
	}

	int GetInfants() const {
		return infants;
	}

	void SetInfants(int infants) {
		this->infants = infants;
	}

	const string& GetTo() const {
		return to;
	}

	void SetTo(const string& to) {
		this->to = to;
	}
};

class FlightReservation: public Reservation {
private:
	FlightRequest request;
	Flight flight;

public:
	FlightReservation(const FlightRequest &request, const Flight &flight) :
			request(request), flight(flight) {
	}

	virtual FlightReservation* Clone() const {
		return new FlightReservation(*this);
	}

	virtual double TotalCost() const override {
		return flight.GetTotalCost();
	}
};

class IFlighsManager {
protected:
	FlightRequest request;
public:
	virtual void SetFlightRequest(const FlightRequest &request_) {
		request = request_;
	}
	virtual vector<Flight> SearchFlights() = 0;
	virtual ~IFlighsManager() {
	}
};

class AirCanadaFlighsManager: public IFlighsManager {
public:
	virtual vector<Flight> SearchFlights() {
		vector<AirCanadaFlight> flights_aircanada = AirCanadaOnlineAPI::GetFlights(request.GetFrom(), request.GetDatePartFrom(), request.GetTo(), request.GetDatePartTo(), request.GetAdults(), request.GetChildern());
		vector<Flight> flights;

		// convert
		for (auto & flight_aircanada : flights_aircanada) {
			Flight flight(this);
			flight.SetDateTimeFrom(flight_aircanada.date_time_from);
			flight.SetDateTimeTo(flight_aircanada.date_time_to);
			flight.SetTotalCost(flight_aircanada.price);

			flights.push_back(flight);
		}
		return flights;
	}
};

class TurkishFlighsManager: public IFlighsManager {
private:
	TurkishAirlinesOnlineAPI api;
public:
	virtual vector<Flight> SearchFlights() {
		api.SetFromToInfo(request.GetDatetimeFrom(), request.GetFrom(), request.GetDatetimeTo(), request.GetTo());
		api.SetPassengersInfo(request.GetInfants(), request.GetChildern(), request.GetAdults());

		vector<TurkishFlight> flights_turkey = api.GetAvailableFlights();
		vector<Flight> flights;

		// convert
		for (auto & flight_turkey : flights_turkey) {
			Flight flight(this);
			flight.SetDateTimeFrom(flight_turkey.datetime_from);
			flight.SetDateTimeTo(flight_turkey.datetime_to);
			flight.SetTotalCost(flight_turkey.cost);

			flights.push_back(flight);
		}
		return flights;
	}
};

class FlightsFactory {
public:
	static vector<IFlighsManager*> GetFlighsManagers() {
		vector<IFlighsManager*> flights_managers;

		flights_managers.push_back(new TurkishFlighsManager());
		flights_managers.push_back(new AirCanadaFlighsManager());

		return flights_managers;
	}
};

#endif /* EXPEDIA_FLIGHTS_API_H_ */
