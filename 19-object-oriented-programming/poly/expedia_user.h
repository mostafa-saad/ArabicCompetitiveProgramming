/*
 * expedia_user.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_USER_H_
#define EXPEDIA_USER_H_

#include <bits/stdc++.h>
using namespace std;

#include "expedia_backend.h"
#include "expedia_payment_card.h"
#include "expedia_common_reservation.h"
#include "expedia_hotels_api.h"

enum class UserType {
	CusomterUser = 0, AdminUser = 1
};

class User {
protected:
	string user_name;
	string password;
	string name;
	string email;
	UserType type = UserType::CusomterUser;

public:
	User(const User&) = delete;
	void operator=(const User&) = delete;

	User() {
	}

	virtual ~User() {	// To allow dynamic casting, we need 1+ virtual function
	}

	string ToString() const {
		ostringstream oss;
		oss << "Name: " << user_name;
		if (type == UserType::AdminUser)
			oss << " | Admin";
		oss << "\n";
		oss << "Email: " << email << "\n";
		oss << "User name: " << user_name << "\n";
		return oss.str();
	}

	void Read(const string &user_name) {
		SetUserName(user_name);

		string str;

		cout << "Enter password: ";
		cin >> str;
		SetPassword(str);

		cout << "Enter name: ";
		cin >> str;
		SetName(str);

		cout << "Enter email: ";
		cin >> str;
		SetEmail(str);
	}

	const string& GetEmail() const {
		return email;
	}

	void SetEmail(const string& email) {
		this->email = email;
	}

	const string& GetName() const {
		return name;
	}

	void SetName(const string& name) {
		this->name = name;
	}

	const string& GetPassword() const {
		return password;
	}

	void SetPassword(const string& password) {
		this->password = password;
	}

	const string& GetUserName() const {
		return user_name;
	}

	void SetUserName(const string& userName) {
		user_name = userName;
	}

	UserType GetType() const {
		return type;
	}

	void SetType(UserType type) {
		this->type = type;
	}
};

class Customer: public User {
protected:
	vector<PaymentCard*> cards;	// * to allow polymophism
	ReservationsGroup reservations;

public:
	Customer(const Customer&) = delete;
	void operator=(const Customer&) = delete;

	Customer() {
		SetType(UserType::CusomterUser);
	}

	~Customer() {
		for (PaymentCard* card : cards)
			delete card;
		cards.clear();
	}

	void AddPaymentCard(const PaymentCard& card) {
		cards.push_back(card.Clone());
	}

	void AddReservation(const Reservation& reservation) {
		reservations.AddReservation(*reservation.Clone());
	}

	const vector<PaymentCard*>& GetCards() const {
		return cards;
	}
};

class Admin: public User {
protected:
public:
	Admin(const Admin&) = delete;
	void operator=(const Admin&) = delete;
	Admin() {
		SetType(UserType::AdminUser);
	}
};

class UsersManager {
protected:
	User* current_user = nullptr;
	map<string, User*> userame_userobject_map;

	void FreeLoadedData() {
		for (auto pair : userame_userobject_map) {
			delete pair.second;
		}
		userame_userobject_map.clear();
	}

public:

	UsersManager() :
			current_user(new User()) {
	}

	~UsersManager() {
		cout << "Destructor: UsersManager\n";
		FreeLoadedData();

		if (current_user != nullptr) {
			delete current_user;
			current_user = nullptr;
		}
	}

	UsersManager(const UsersManager&) = delete;
	void operator=(const UsersManager&) = delete;

	void LoadDatabase() {
		cout << "UsersManager: LoadDatabase\n";

		FreeLoadedData();
		// Some "Dummy Data" for simplicity
		Customer* customrUser = new Customer();
		customrUser->SetUserName("mostafa");
		customrUser->SetPassword("111");
		customrUser->SetEmail("most@gmail.com");
		//user1->SetIsLibraryAdmin(true);
		customrUser->SetName("Mostafa Saad Ibrahim");

		DebitCard* debitCard = new DebitCard();
		debitCard->SetOwnerName(customrUser->GetName());
		debitCard->SetCardNumber("11-22-33-44");
		debitCard->SetExpiryDate("11/20");
		debitCard->SetSecurityCode(111);
		debitCard->SetBillingAddress("111 hello st, BC, Canada");
		customrUser->AddPaymentCard(*debitCard);

		CreditCard* creditCard = new CreditCard();
		creditCard->SetOwnerName(customrUser->GetName());
		creditCard->SetCardNumber("22-11-03-44");
		creditCard->SetExpiryDate("11/25");
		creditCard->SetSecurityCode(1117);
		customrUser->AddPaymentCard(*creditCard);

		userame_userobject_map[customrUser->GetUserName()] = customrUser;

		Admin* user2 = new Admin();
		user2->SetUserName("asmaa");
		user2->SetPassword("222");
		user2->SetEmail("asmaa@gmail.com");
		//user2->SetIsLibraryAdmin(false);
		user2->SetName("Asmaa Saad Ibrahim");
		userame_userobject_map[user2->GetUserName()] = user2;
	}

	void AccessSystem() {
		int choice = ShowReadMenu( { "Login", "Sign Up" });
		if (choice == 1)
			DoLogin();
		else
			DoSignUp();
	}

	void DoLogin() {
		LoadDatabase();

		while (true) {
			string name, pass;
			cout << "Enter user name & password: ";
			cin >> name >> pass;
			current_user->SetUserName(name);
			current_user->SetPassword(pass);

			if (!userame_userobject_map.count(current_user->GetUserName())) {
				cout << "\nInvalid user name or password. Try again\n\n";
				continue;
			}
			User* user_exist = userame_userobject_map.find(current_user->GetUserName())->second;

			if (current_user->GetPassword() != user_exist->GetPassword()) {
				cout << "\nInvalid user name or password. Try again\n\n";
				continue;
			}
			delete current_user;
			current_user = user_exist;
			break;
		}
	}

	void DoSignUp() {
		string user_name;
		while (true) {
			cout << "Enter user name. (No spaces): ";
			cin >> user_name;

			if (userame_userobject_map.count(user_name))
				cout << "Already used. Try again\n";
			else
				break;
		}

		current_user->Read(user_name);
		userame_userobject_map[current_user->GetUserName()] = current_user;
	}

	User* GetCurrentUser() const {
		// For simplicity, I don't return it as const, which is not good
		// One ok way: return as const, and user support clone + copy contstructor. Then caller can make his own copy
		return current_user;
	}
};

class CustomerManager {
private:
	Customer *customer;
	ExpediaBackend &expedia_manager;

public:
	CustomerManager(User *user, ExpediaBackend &expedia_manager) :
			customer(dynamic_cast<Customer*>(customer)), expedia_manager(expedia_manager) {
		assert(customer != nullptr);
	}

	vector<Flight> FindFlights(const FlightRequest &request) {
		return expedia_manager.FindFlights(request);
	}

	vector<HotelRoom> FindHotels(const HotelRequest &request) {
		return expedia_manager.FindHotels(request);
	}

	vector<string> GetPaymentChoices() {
		vector<string> cards_info;

		for (PaymentCard* card : customer->GetCards())
			cards_info.push_back(card->ToString());
		return cards_info;
	}

	bool MakeReservation(const Reservation& reservation, PaymentCard &payment_card) {
		bool is_paid = expedia_manager.ChargeCost(reservation.TotalCost(), payment_card);

		if (is_paid)
			customer->AddReservation(reservation);

		return is_paid;
	}

	const Customer* GetCustomer() const {
		return customer;
	}
};

class CustomerView {
private:
	CustomerManager &customer_manager;
	const Customer& customer;
	ItineraryReservation current_itinerary;

	void ReadFlightRequest(FlightRequest &request) {
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
		request.SetChildern(val);
		cin >> val;
		request.SetInfants(val);
	}

	void ReadHotelRequest(HotelRequest &request) {
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

	int ChooseFlight(const vector<Flight> &flights) {
		if (flights.size() == 0) {
			cout << "No trips for this request info\n";
			return -1;
		}

		for (const Flight& flight : flights) {
			cout << flight.ToString() << "\n";
		}

		return ReadInt(1, flights.size(), true);
	}

	int ChooseRoom(const vector<HotelRoom> &rooms) {
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

		Flight &flight = flights[flight_choice];

		current_itinerary.AddReservation(FlightReservation(request, flight));
	}

	void AddHotel() {
		HotelRequest request;
		ReadHotelRequest(request);

		vector<HotelRoom> rooms = customer_manager.FindHotels(request);
		int hotel_choice = ChooseRoom(rooms);

		if (hotel_choice == -1)
			return;

		HotelRoom &room = rooms[hotel_choice];

		current_itinerary.AddReservation(HotelReservation(request, room));
	}

	void PayItinerary() {
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
		menu.push_back("Logout");

		while (true) {
			int choice = ShowReadMenu(menu);
			if (choice == 1)
				ViewProfile();
			else if (choice == 2)
				MakeItinerary();
			else
				break;
		}
	}

	void ViewProfile() {
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
				break;
			} else {
				current_itinerary.Clear();
				break;
			}
		}

	}
};

#endif /* EXPEDIA_USER_H_ */
