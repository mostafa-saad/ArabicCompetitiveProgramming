#include <bits/stdc++.h>
using namespace std;


class Printable {
public:
	virtual void Print() const = 0;
	virtual ~Printable() {
	}
};


class Cloneable {
public:
	// function to clone
	virtual ~Cloneable() {
	}
};

class Person : public Printable,
			   public Cloneable {

};

class Employee : public Person {

};

int main() {


	return 0;
}

