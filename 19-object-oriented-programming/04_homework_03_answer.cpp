#include <bits/stdc++.h>
using namespace std;

class Room {
private:
	int width;
	int height;
	string color;

public:
	const string& GetColor() {
		return color;
	}

	void SetColor(const string& color) {
		this->color = color;
	}

	int GetHeight() {
		return height;
	}

	void SetHeight(int height) {
		this->height = height;
	}

	int GetWidth() {
		return width;
	}

	void SetWidth(int width) {
		this->width = width;
	}
};

class Apartment {
private:
	vector<Room> rooms;
	vector<Room> bathroom;
	int floor_number;
	int apartment_number;

public:
	int GetApartmentNumber() {
		return apartment_number;
	}

	void SetApartmentNumber(int apartmentNumber) {
		apartment_number = apartmentNumber;
	}

	int GetFloorNumber() {
		return floor_number;
	}

	void SetFloorNumber(int floorNumber) {
		floor_number = floorNumber;
	}

	const vector<Room>& GetRooms() {
		return rooms;
	}

	void SetRooms(const vector<Room>& rooms) {
		this->rooms = rooms;
	}

	const vector<Room>& GetBathroom() {
		return bathroom;
	}

	void SetBathroom(const vector<Room>& bathroom) {
		this->bathroom = bathroom;
	}
};

class Elevator {
private:
	int width;
	int height;
	int max_people;
	int max_weight;
	// Date: installation date, last maintenance date, manufacture

public:
	int GetHeight() {
		return height;
	}

	void SetHeight(int height) {
		this->height = height;
	}

	int GetMaxPeople() {
		return max_people;
	}

	void SetMaxPeople(int maxPeople) {
		max_people = maxPeople;
	}

	int GetMaxWeight() {
		return max_weight;
	}

	void SetMaxWeight(int maxWeight) {
		max_weight = maxWeight;
	}

	int GetWidth() {
		return width;
	}

	void SetWidth(int width) {
		this->width = width;
	}
};

class Building {
private:
	vector<Apartment> apartments;
	vector<Elevator> elevators;
};

int main() {

	__gcd(2, 8);

	return 0;
}
