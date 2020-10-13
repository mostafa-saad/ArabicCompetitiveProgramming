#include <bits/stdc++.h>
using namespace std;

class Payable {
public:
	virtual double GetAmountToPay() const {}
	virtual ~Payable() {
	}
};

class StaffMember: public Payable {
private:
	string name;
	string address;
public:
};

class Employee: public StaffMember {
private:
	int day_to_pay;
public:

};

class HourlyEmployee: public Employee {
private:
	int total_working_hours;
	double salary_per_hour;
public:
	virtual double GetAmountToPay() const override {
		cout << "HourlyEmployee\n";
		return total_working_hours * salary_per_hour;
	}
};

class SalariedEmployee: public Employee {
private:
	double monthly_salary;
public:
	virtual double GetAmountToPay() const override {
		cout << "SalariedEmployee\n";
		return monthly_salary;
	}
};

class CommisionSalariedEmployee: public SalariedEmployee {
private:
	double commision_rate;
	double current_month_sales;
public:
	virtual double GetAmountToPay() const override {
		cout << "CommisionSalariedEmployee\n";
		return SalariedEmployee::GetAmountToPay() + current_month_sales * commision_rate;
	}
};

class Volunteer: public StaffMember {
private:
	int current_payment;
public:
	virtual double GetAmountToPay() const override {
		return current_payment;
	}
};

class Item {
private:
	string desc;
	double price;
	int quantity;
public:
	double GetPrice() const {
		return price * quantity;
	}
};

class Book: public Item {
private:
	string author;
};

class Food: public Item {
private:
	string expiration_date;
};

class Invoice: public Payable {
private:
	int invoice_id = -1;
	vector<Item*> items;
public:
	void AddItem(Item* item) {
		items.push_back(item);
	}

	virtual double GetAmountToPay() const override {
		cout << "Invoice\n";

		double sum = 0;
		for (const Item* item_ptr : items)
			sum += item_ptr->GetPrice();
		return sum;
	}
};

class Payroll {
private:
	vector<Payable*> payables;

public:
	void AddPayable(Payable* payable) {
		payables.push_back(payable);	// we should add copy
	}
	void Pay() {
		cout << "Payroll::Pay\n";
		;
		for (const auto payable : payables)
			payable->GetAmountToPay();
	}
};

class Company {
private:
	Payroll payroll;
public:
	Company() {
	}

	void Run() {
		payroll.AddPayable(new Volunteer());
		payroll.AddPayable(new HourlyEmployee());
		payroll.AddPayable(new SalariedEmployee());
		payroll.AddPayable(new CommisionSalariedEmployee());

		Invoice* invoice = new Invoice();
		invoice->AddItem(new Book());
		invoice->AddItem(new Food());

		payroll.AddPayable(invoice);

		payroll.Pay();
	}
};

int main() {
	Company company;
	company.Run();

	return 0;
}

/*

Payroll::Pay
HourlyEmployee
SalariedEmployee
CommisionSalariedEmployee
SalariedEmployee
Invoice

 */
