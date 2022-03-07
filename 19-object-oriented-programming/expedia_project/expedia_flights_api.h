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

class AirCanadaCustomerInfo {

};

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
	static bool ReserveFlight(const AirCanadaFlight& flight, const AirCanadaCustomerInfo &info) {
		return true;
	}
};

class TurkishFlight {
public:
	double cost;
	string datetime_from;
	string datetime_to;
};

class TurkishCustomerInfo {

};

class TurkishAirlinesOnlineAPI {
public:
	void SetFromToInfo(string datetime_from, string from, string datetime_to, string to) {
	}
	void SetPassengersInfo(int infants, int childern, int adults) {
	}
	vector<TurkishFlight> GetAvailableFlights() const {
		vector<TurkishFlight> flights;

		flights.push_back( { 300, "10-01-2022", "10-02-2022" });
		flights.push_back( { 320, "12-01-2022", "10-02-2022" });
		return flights;
	}

	static bool ReserveFlight(const TurkishCustomerInfo &info, const TurkishFlight& flight) {
		return false;
	}
};

////////////////////////////////

class Flight {
private:
	string airline_name;
	double total_cost = 0;
	string date_time_from;
	string date_time_to;

public:
	string ToString() const {
		ostringstream oss;
		oss << "Airline: " << airline_name << " Cost: " << total_cost << " Departure Date " << date_time_from << " Arrival date " << date_time_to;
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

	const string& GetAirlineName() const {
		return airline_name;
	}

	void SetAirlineName(const string& airlineName) {
		airline_name = airlineName;
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
	string GetDatePartFrom() const {
		return datetime_from;	// extract date only
	}

	string GetDatePartTo() const {
		return datetime_to;	// extract date only
	}

	int GetAdults() const {
		return adults;
	}

	void SetAdults(int adults) {
		this->adults = adults;
	}

	int GetChildren() const {
		return childern;
	}

	void SetChildren(int childern) {
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

	virtual FlightReservation* Clone() const override {
		return new FlightReservation(*this);
	}

	virtual double TotalCost() const override {
		return flight.GetTotalCost();
	}

	virtual string ToString() const override {
		ostringstream oss;
		oss << "Airline reservation with reservation: " << flight.GetAirlineName() << ": From " << request.GetFrom() << " on " << request.GetDatetimeFrom() << "\n";
		oss << "\tTo " << request.GetTo() << " on " << request.GetDatetimeTo() << "\n";
		oss << "\t" << "Adults: " << request.GetAdults() << " children: " << request.GetChildren() << " infants: " << request.GetInfants() << "\n";
		oss << "\tTotal Cost:" << TotalCost() << "\n";

		return oss.str();
	}

	const Flight& GetFlight() const {
		return flight;
	}

	const FlightRequest& GetRequest() const {
		return request;
	}
};

class IFlighsManager {
protected:
	FlightRequest request;
public:
	virtual void SetFlightRequest(const FlightRequest &request_) {
		request = request_;
	}
	virtual vector<Flight> SearchFlights() const = 0;

	virtual bool ReserveFlight(const FlightReservation &reservation) const = 0;

	virtual string GetName() const = 0;

	virtual ~IFlighsManager() {
	}
};

class AirCanadaFlighsManager: public IFlighsManager {
public:
	virtual string GetName() const override {
		return "AirCanada Airlines";
	}

	virtual vector<Flight> SearchFlights() const override {
		vector<AirCanadaFlight> flights_aircanada = AirCanadaOnlineAPI::GetFlights(request.GetFrom(), request.GetDatePartFrom(), request.GetTo(), request.GetDatePartTo(), request.GetAdults(), request.GetChildren());
		vector<Flight> flights;

		// convert
		for (auto & flight_aircanada : flights_aircanada) {
			Flight flight;
			flight.SetAirlineName(GetName());
			flight.SetDateTimeFrom(flight_aircanada.date_time_from);
			flight.SetDateTimeTo(flight_aircanada.date_time_to);
			flight.SetTotalCost(flight_aircanada.price);

			flights.push_back(flight);
		}
		return flights;
	}

	virtual bool ReserveFlight(const FlightReservation &reservation) const {
		// Just dummy. We should map from reservation to the agency api
		return AirCanadaOnlineAPI::ReserveFlight(AirCanadaFlight(), AirCanadaCustomerInfo());
	}
};

class TurkishFlighsManager: public IFlighsManager {
private:
public:
	virtual string GetName() const override {
		return "Turksih Airlines";
	}

	virtual vector<Flight> SearchFlights() const override {
		TurkishAirlinesOnlineAPI api;

		api.SetFromToInfo(request.GetDatetimeFrom(), request.GetFrom(), request.GetDatetimeTo(), request.GetTo());
		api.SetPassengersInfo(request.GetInfants(), request.GetChildren(), request.GetAdults());

		vector<TurkishFlight> flights_turkey = api.GetAvailableFlights();
		vector<Flight> flights;

		// convert
		for (auto & flight_turkey : flights_turkey) {
			Flight flight;
			flight.SetAirlineName("Turksih Airlines");
			flight.SetDateTimeFrom(flight_turkey.datetime_from);
			flight.SetDateTimeTo(flight_turkey.datetime_to);
			flight.SetTotalCost(flight_turkey.cost);

			flights.push_back(flight);
		}
		return flights;
	}
	virtual bool ReserveFlight(const FlightReservation &reservation) const {
		// Just dummy. We should map from reservation to the agency api
		return TurkishAirlinesOnlineAPI::ReserveFlight(TurkishCustomerInfo(), TurkishFlight());
	}
};

/*
 * This class reduce the dependency of clients on specific managers. This is the only place that is coupled with the different types
 */
class FlightsFactory {
	// We can design this factory in more efficient way: e.g. using map + singleton
public:
	static vector<IFlighsManager*> GetManagers() {
		vector<IFlighsManager*> flights_managers;

		flights_managers.push_back(new TurkishFlighsManager());
		flights_managers.push_back(new AirCanadaFlighsManager());

		return flights_managers;
	}

	static IFlighsManager* GetManager(string name) {
		for (IFlighsManager* mgr : FlightsFactory::GetManagers()) {
			if (mgr->GetName() == name)
				return mgr;
		}
		return nullptr;
	}
};

#endif /* EXPEDIA_FLIGHTS_API_H_ */
