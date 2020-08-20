#include <bits/stdc++.h>
using namespace std;


class ClassA {
private:
	int *val;
public:
	ClassA(int v) {
		val = new int;
		*val = v;
	}
	~ClassA() {
		delete val;
		val = NULL;	// good practice
	}

	const int* GetVal() {			// adding const here prevents from wrong usage
		return val;
	}

	void SetVal(int* val) {
		this->val = val;
	}
};

int main() {
	ClassA a1(10);
	ClassA a2(20);
	a2.SetVal(a1.GetVal());
	return 0;
}

/*
The 2 objects now share same pointer.
The first destructor to execute would delete the dynamically allocated memory, 
and the other object’s ptr would point to memory that’s no longer allocated, a situation called a dangling pointer.
This would likely result in a serious runtime error (such as early program termination) when the pointer was used.


By using const, then user can't reset it so we prevent such behaviour

Tip: Rewiew slide Accessor & mutator: The proper way?
	Careful thinking about your setters and getters
	In this scenario, returning pointer can make serious problems
*/
