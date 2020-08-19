#include <bits/stdc++.h>
using namespace std;

class Invoice {
private:
	int item_number;
	string name;
	double price;
	int quantity;

public:
	Invoice(const int &item_number, const string &name, const double &price, const int &quantity = 1);

	int GetItemNumber();
	void SetItemNumber(int itemNumber);
	string& GetName();
	void SetName(string& name);
	double GetPrice();
	void SetPrice(double price);
	int GetQuantity();
	void SetQuantity(int quantity);

	double GetTotalPrice();
	void Print();
	string ToString();
};

Invoice::Invoice(const int &item_number, const string &name, const double &price, const int &quantity) :
		item_number(item_number), name(name), price(price), quantity(quantity) {

}

int Invoice::GetItemNumber() {
	return item_number;
}

void Invoice::SetItemNumber(int itemNumber) {
	item_number = itemNumber;
}

string& Invoice::GetName() {
	return name;
}

void Invoice::SetName(string& name) {
	this->name = name;
}

double Invoice::GetPrice() {
	return price;
}

void Invoice::SetPrice(double price) {
	this->price = price;
}

int Invoice::GetQuantity() {
	return quantity;
}

void Invoice::SetQuantity(int quantity) {
	this->quantity = quantity;
}

double Invoice::GetTotalPrice() {
	return GetPrice() * GetQuantity();
}

void Invoice::Print() {
	cout << "Item Name: " << GetName() << "\n";
	cout << "Item Price: " << GetPrice() << "\n";
	cout << "Item Quantity: " << GetQuantity() << "\n";
	cout << "Item item number: " << GetItemNumber() << "\n";
	cout << "Item Total Price: " << GetTotalPrice() << "\n";
}

string Invoice::ToString() {
	ostringstream oss;
	oss << GetName() << "," << GetPrice() << "," << GetQuantity() << "," << GetItemNumber();
	return oss.str();
}

// In proper class, there will be more verifications in the class and better coding

int main() {
	return 0;
}
