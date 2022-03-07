/*
 * expedia_hotels_api.h
 *
 *  Created on: Sep 22, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_HOTELS_API_H_
#define EXPEDIA_HOTELS_API_H_

#include <bits/stdc++.h>
using namespace std;

#include "expedia_common_reservation.h"

class HiltonRoom {
public:
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
};

class HiltonHotelAPI {
public:
	static vector<HiltonRoom> SearchRooms(string country, string city, string from_date, string to_date, int adults, int children, int needed_rooms) {
		vector<HiltonRoom> rooms;

		rooms.push_back( { "Interior View", 6, 200.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "City View", 3, 300.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Deluxe View", 8, 500.0, "29-01-2022", "10-02-2022" });

		return rooms;
	}
};

class MarriottFoundRoom {
public:
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
};

class MarriottHotelAPI {
public:
	static vector<MarriottFoundRoom> FindRooms(string from_date, string to_date, string country, string city, int needed_rooms, int adults, int children) {
		vector<MarriottFoundRoom> rooms;

		rooms.push_back( { "City View", 8, 320.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Interior View", 8, 220.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Private View", 5, 600.0, "29-01-2022", "10-02-2022" });

		return rooms;
	}
};

///////////////////////////////////

class HotelRoom {
private:
	string hotel_name;
	string room_type;
	int available_rooms = 0;
	double price_per_night = 0;
	string date_from;
	string date_to;

public:
	string ToString() const {
		ostringstream oss;
		oss << "Hotel: " << hotel_name << " Room Type: " << room_type << "(" << available_rooms << ") Price per night: " << price_per_night << " From Date " << date_from << " to " << date_to << "";
		return oss.str();
	}

	const string& GetDateFrom() const {
		return date_from;
	}

	void SetDateFrom(const string& dateFrom) {
		date_from = dateFrom;
	}

	const string& GetDateTo() const {
		return date_to;
	}

	void SetDateTo(const string& dateTo) {
		date_to = dateTo;
	}

	double GetPricePerNight() const {
		return price_per_night;
	}

	void SetPricePerNight(double pricePerNight) {
		price_per_night = pricePerNight;
	}

	const string& GetRoomType() const {
		return room_type;
	}

	void SetRoomType(const string& roomType) {
		room_type = roomType;
	}

	int GetAvailableRooms() const {
		return available_rooms;
	}

	void SetAvailableRooms(int availableRooms = 0) {
		available_rooms = availableRooms;
	}

	const string& GetHotelName() const {
		return hotel_name;
	}

	void SetHotelName(const string& hotelName) {
		hotel_name = hotelName;
	}
};

class HotelRequest {
private:
	string from_date;
	string to_date;
	string country;
	string city;
	int rooms;
	int adults;
	int children;

public:
	int GetTotalNights() const {
		// Some date computations
		return 3;
	}
	int GetAdults() const {
		return adults;
	}

	void SetAdults(int adults) {
		this->adults = adults;
	}

	int GetChildren() const {
		return children;
	}

	void SetChildren(int children) {
		this->children = children;
	}

	const string& GetCity() const {
		return city;
	}

	void SetCity(const string& city) {
		this->city = city;
	}

	const string& GetCountry() const {
		return country;
	}

	void SetCountry(const string& country) {
		this->country = country;
	}

	const string& GetFromDate() const {
		return from_date;
	}

	void SetFromDate(const string& fromDate) {
		from_date = fromDate;
	}

	int GetRooms() const {
		return rooms;
	}

	void SetRooms(int rooms) {
		this->rooms = rooms;
	}

	const string& GetToDate() const {
		return to_date;
	}

	void SetToDate(const string& toDate) {
		to_date = toDate;
	}
};

class HotelReservation: public Reservation {
private:
	HotelRequest request;
	HotelRoom room;

public:
	HotelReservation(const HotelRequest &request, const HotelRoom &room) :
			request(request), room(room) {
	}

	virtual HotelReservation* Clone() const override {
		return new HotelReservation(*this);
	}

	virtual double TotalCost() const override {
		return room.GetPricePerNight() * request.GetTotalNights();
	}

	virtual string ToString() const override {
		ostringstream oss;
		oss << "Hotel reservation: " << room.GetHotelName() << ": " << request.GetCity() << " @ " << request.GetCountry() << "\n";
		oss << "\t" << request.GetFromDate() << " to " << request.GetToDate() << " : " << request.GetTotalNights() << "\n";
		oss << "\t" << "Adults: " << request.GetAdults() << " children " << request.GetChildren() << "\n";
		oss << "\tTotal Cost:" << TotalCost() << "\n";

		return oss.str();
	}

	const HotelRequest& GetRequest() const {
		return request;
	}

	const HotelRoom& GetRoom() const {
		return room;
	}
};

class IHotelsManager {
protected:
	HotelRequest request;
public:
	virtual string GetName() const = 0;

	virtual void SetHotelRequest(const HotelRequest &request_) {
		request = request_;
	}
	virtual vector<HotelRoom> SearchHotelRooms() = 0;

	virtual bool ReserveRoom(const HotelReservation &reservation) const = 0;

	virtual ~IHotelsManager() {
	}
};

class HiltonHotelsManager: public IHotelsManager {
private:

public:
	virtual string GetName() const override {
		return "Hilton Hotel";
	}

	virtual vector<HotelRoom> SearchHotelRooms() {
		vector<HiltonRoom> api_rooms = HiltonHotelAPI::SearchRooms(request.GetCountry(), request.GetCity(), request.GetFromDate(), request.GetToDate(), request.GetAdults(), request.GetChildren(), request.GetRooms());
		vector<HotelRoom> rooms;

		for (auto & api_room : api_rooms) {
			HotelRoom room;
			room.SetHotelName("Hilton Hotel");
			room.SetDateFrom(api_room.date_from);
			room.SetDateTo(api_room.date_to);
			room.SetPricePerNight(api_room.price_per_night);
			room.SetAvailableRooms(api_room.available);
			room.SetRoomType(api_room.room_type);

			rooms.push_back(room);
		}
		return rooms;
	}

	virtual bool ReserveRoom(const HotelReservation &reservation) const override{
		return true;
	}
};

class MarriottHotelsManager: public IHotelsManager {
private:

public:
	virtual string GetName() const override {
		return "Marriott Hotel";
	}

	virtual vector<HotelRoom> SearchHotelRooms() {
		//string from_date, string to_date, string country, string city, int needed_rooms, int adults, int children
		vector<MarriottFoundRoom> api_rooms = MarriottHotelAPI::FindRooms(request.GetFromDate(), request.GetToDate(), request.GetCountry(), request.GetCity(), request.GetRooms(), request.GetAdults(), request.GetChildren());
		vector<HotelRoom> rooms;

		for (auto & api_room : api_rooms) {
			HotelRoom room;
			room.SetHotelName("Marriott Hotel");
			room.SetDateFrom(api_room.date_from);
			room.SetDateTo(api_room.date_to);
			room.SetPricePerNight(api_room.price_per_night);
			room.SetAvailableRooms(api_room.available);
			room.SetRoomType(api_room.room_type);

			rooms.push_back(room);
		}
		return rooms;
	}
	virtual bool ReserveRoom(const HotelReservation &reservation) const override{
		return true;
	}
};

class HotelsFactory {
public:
	static vector<IHotelsManager*> GetManagers() {
		vector<IHotelsManager*> managers;

		managers.push_back(new HiltonHotelsManager());
		managers.push_back(new MarriottHotelsManager());

		return managers;
	}

	static IHotelsManager* GetManager(string name) {
		for (IHotelsManager* mgr : HotelsFactory::GetManagers()) {
			if (mgr->GetName() == name)
				return mgr;
		}
		return nullptr;
	}
};

#endif /* EXPEDIA_HOTELS_API_H_ */
