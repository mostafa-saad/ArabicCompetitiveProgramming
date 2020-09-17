#include <bits/stdc++.h>
using namespace std;

class Payable {
public:
	virtual double GetAmountToPay() const = 0;
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

class Invoice;

class VaidationRule {
public:
	virtual bool ValidateRule(const Invoice* const invoice) = 0;
	virtual ~VaidationRule() {}
};

class InvoiceValidator {
protected:
	vector<VaidationRule*> rules;
public:
	virtual bool ValidateInvoice(const Invoice* const invoice) {
		cout << "Validator\n";
		for (const auto rule_ptr : rules)
			rule_ptr->ValidateRule(invoice);	// ask child: inverse of control
	}
	virtual ~InvoiceValidator() {
	}
};

class Invoice: public Payable {
private:
	int invoice_id = -1;
	vector<Item*> items;
	InvoiceValidator* validator;	// doesn't know which validator/rule
public:
	Invoice(InvoiceValidator* validator) :
			validator(validator) {
	}

	void AddItem(Item* item) {
		items.push_back(item);
	}

	virtual double GetAmountToPay() const override {
		cout << "Invoice\n";
		validator->ValidateInvoice(this);

		double sum = 0;
		for (const Item* item_ptr : items)
			sum += item_ptr->GetPrice();
		return sum;
	}
};

class TaxesVaidationRule: public VaidationRule {
public:
	virtual bool ValidateRule(const Invoice* const invoice) {
		cout << "Tax Validation rule\n";
		return true;
	}
};

class SuppliersDealsVaidationRule: public VaidationRule {
public:
	virtual bool ValidateRule(const Invoice* const invoice) {
		cout << "Suppliers deals validation rule\n";
		return true;
	}
};

class MandatoryInvoiceValidator: public InvoiceValidator {
public:
	MandatoryInvoiceValidator() {	// could be singleton
		rules.push_back(new TaxesVaidationRule());
	}
};

class CompleteInvoiceValidator: public InvoiceValidator {
public:
	CompleteInvoiceValidator() {	// could be singleton
		rules.push_back(new TaxesVaidationRule());
		rules.push_back(new SuppliersDealsVaidationRule());
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
	bool is_use_complete_validations = true;
	InvoiceValidator* validator = nullptr;
	Payroll payroll;
public:
	Company() {
		if (is_use_complete_validations)
			validator = new CompleteInvoiceValidator();
		else
			validator = new MandatoryInvoiceValidator();
	}

	void Run() {
		payroll.AddPayable(new Volunteer());
		payroll.AddPayable(new HourlyEmployee());
		payroll.AddPayable(new SalariedEmployee());
		payroll.AddPayable(new CommisionSalariedEmployee());

		Invoice* invoice = new Invoice(validator);
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
Validator
Tax Validation rule
Suppliers deals validation rule


 */
