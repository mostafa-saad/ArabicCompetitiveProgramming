#include <bits/stdc++.h>
using namespace std;

class Object {	// make it a polymorphic class
public:
	virtual string GetClassName() const = 0;

	virtual ~Object() {
	}
};

class Cloneable: virtual public Object {
public:
	virtual Object* Clone() const = 0;
	virtual ~Cloneable() {
	}
};

class Printable: virtual public Object {
public:
	virtual void Print(ostream& out) const = 0;

	virtual ~Printable() {
	}
};

// Inverse of control. We implement this operator here ONLY once
// Call the print function, which will be known in runtime! Cheers!
// This way we don't have to provide several overloaded versions of it!
ostream& operator <<(ostream& out, const Printable & p) {
	p.Print(out);
	return out;
}

class Comparable: virtual public Object {
public:
	virtual bool operator < (Object& obj) const = 0;
	virtual ~Comparable() {
	}
};

class Payable: public Cloneable, public Printable, public Comparable {
public:
	virtual double GetAmountToPay() const = 0;
	virtual ~Payable() {
	}
};

class Employee: public Payable {
private:
	double salary;
	string name;
public:
	Employee(double salary, string name) :
			salary(salary), name(name) {
	}

	virtual string GetClassName() const override {
		return "Employee";
	}

	virtual Object* Clone() const override {
		return new Employee(*this);	// Default copy constructor is good, as no internal pointers so far
	}

	virtual void Print(ostream& out) const override {
		out << "Employee " << name << " has salary " << salary << "\n";
	}

	double GetAmountToPay() const override {
		return salary;
	}

	virtual bool operator < (Object& obj) const override {
		if (GetClassName() != obj.GetClassName())
			return GetClassName() < obj.GetClassName();

		Employee* another_ptr = nullptr;
		if ((another_ptr = dynamic_cast<Employee*>(&obj)))
			return tie(salary, name) < tie(another_ptr->salary, another_ptr->name);
		else
			return false;	// Not an employee!
	}
};

class Invoice: public Payable {
private:
	double cost;
public:
	Invoice(double cost) :
			cost(cost) {
	}

	virtual string GetClassName() const override {
		return "Invoice";
	}

	virtual Object* Clone() const override {
		return new Invoice(*this);
	}

	virtual void Print(ostream& out) const override {
		out << "Invoice cost " << cost << "\n";
	}

	double GetAmountToPay() const override {
		return cost;
	}

	virtual bool operator < (Object& obj) const override {
		if (GetClassName() != obj.GetClassName())
			return GetClassName() < obj.GetClassName();

		Invoice* another_ptr = nullptr;
		if ((another_ptr = dynamic_cast<Invoice*>(&obj)))
			return cost < another_ptr->cost;
		else
			return false;
	}
};

class Sortable: virtual public Object {
public:
	virtual void OrderItems() = 0;
	virtual ~Sortable() {
	}
};

bool Compare(Payable* obj1, Payable* obj2) {
	return *obj1 < *obj2;
}

class CompanyPayroll: public Printable, public Sortable {
private:
	vector<Payable*> payables;

public:
	CompanyPayroll() {
	}
	// Prevent copy constructor
	CompanyPayroll(const CompanyPayroll&) = delete;
	// Prevent assignment operator
	void operator=(const CompanyPayroll&) = delete;

	void AddPayable(const Payable& payable) {
		payables.push_back(dynamic_cast<Payable*>(payable.Clone()));
	}

	virtual string GetClassName() const override {
		return "CompanyPayroll";
	}

	virtual void Print(ostream& out) const override {
		double to_pay_sum = 0;

		for (auto payable : payables) {
			// Below is wrong. it prints address. Use * to print object
			//out<<payable;

			out<<*payable;
			to_pay_sum += payable->GetAmountToPay();
		}

		out << "Total to be paid: " << to_pay_sum << "\n";
	}

	virtual void OrderItems() override {
		sort(payables.begin(), payables.end(), Compare);

		// Below is wrong as it compares pointer address with pointer address
		// If you did not use a function, it will compare ptr1 < ptr2 as pointers in memory NOT as actual objects
		// sort(payables.begin(), payables.end());
	}

	~CompanyPayroll() {

		for (auto payable : payables)
			delete payable;
		payables.clear();
	}
};

void test() {
	CompanyPayroll payroll;

	payroll.AddPayable(Employee(50, "mostafa"));
	payroll.AddPayable(Invoice(200));
	payroll.AddPayable(Employee(10, "ziad"));
	payroll.AddPayable(Invoice(100));
	payroll.AddPayable(Employee(30, "belal"));
	payroll.AddPayable(Invoice(300));

	payroll.OrderItems();
	cout<<payroll;

	/*
Employee ziad has salary 10
Employee belal has salary 30
Employee mostafa has salary 50
Invoice cost 100
Invoice cost 200
Invoice cost 300
Total to be paid: 690
	 */
}

int main() {
	test();

	return 0;
}

