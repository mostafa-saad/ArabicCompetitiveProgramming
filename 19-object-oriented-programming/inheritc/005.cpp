#include <bits/stdc++.h>
using namespace std;

/*
class MyClass {
private:
	int pri;
	void PriFunc() {
	}
protected:
	int pro;
	void PRoFunc() {
	}

public:
	int pub;
	void PubFunc() {
	}
};

class Student {
protected:
	double gpa;
};

class Employee {
protected:
	double salary;
};

class TeachingAssistant: public Student, public Employee {
private:
	vector<int> courses_ids;

	void func() {
		gpa = 3.5;
		salary = 5000.0;
	}
};
*/

class Person {
protected:
	string name;
};

class Student : public Person {
protected:
	string student_id;
};

class Graduate : public Student {
protected:
	int graduation_year;

public:
	void reset() {
		name = student_id = "";
	}
};



int main() {


	return 0;
}
