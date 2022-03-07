#include <bits/stdc++.h>
using namespace std;

/*

 Observe that: copy constructors and operators can directly access private variables
 of another object of same class
 https://stackoverflow.com/questions/4117002/why-can-i-access-private-variables-in-the-copy-constructor
 */

class Array {
private:
	int size;
	int *ptr;

public:
	~Array() {
		delete[] ptr;
		ptr = nullptr;
	}

	explicit Array(int size = 100) :
			size(size), ptr(new int[size]) {
		for (int i = 0; i < size; ++i)
			ptr[i] = 0;
	}
	Array(const Array &another) :	// copy constructor
			size(another.size), ptr(new int[size]) {
		for (int i = 0; i < size; ++i)
			ptr[i] = another.ptr[i];
	}

	int getSize() const {
		return size;
	}

	Array &operator=(const Array &another) {	// assign operator
		if (&another != this) { // Check self-assignment
			if (size != another.size) {
				delete[] ptr;
				size = another.size;
				ptr = new int[size];
			}
			for (int i = 0; i < size; ++i)
				ptr[i] = another.ptr[i];
		}
		return *this;
	}

	int &operator[](int pos) {
		return ptr[pos];
	}

	int operator[](int pos) const {
		return ptr[pos];
	}

	bool operator==(const Array &another) const {
		if (size != another.size)
			return false;

		for (int i = 0; i < size; ++i)
			if (ptr[i] != another.ptr[i])
				return false;

		return true;
	}

	bool operator!=(const Array &another) const {
		// Don't duplicate. Call  operator==
		return !(*this == another);
	}

	Array& operator++() {	// prefix
		for (int i = 0; i < size; ++i)
			++ptr[i];
		return *this;
	}

	Array operator++(int) {	// postfix
		Array cpy = *this;
		++*this;	// Don't duplicate. Call  ++object
		return cpy;
	}

	friend istream &operator>>(istream &input, Array &arr);
	friend ostream &operator<<(ostream &output, const Array &arr);
};

istream &operator>>(istream &input, Array &arr) {
	for (int i = 0; i < arr.size; ++i)
		input >> arr.ptr[i];
	return input;
}

ostream &operator<<(ostream &output, const Array &arr) {
	for (int i = 0; i < arr.size; ++i)
		output << arr.ptr[i] << " ";
	output << "\n";

	return output;
}

void test_Array() {
	Array arr1(6);

	int counter = 0;
	for (int i = 0; i < arr1.getSize(); ++i)
		arr1[i] = counter++;

	cout<<arr1<<"\n";

	Array arr2 = ++arr1;	// copy
	cout<<arr2<<"\n";

	if(arr2 == arr1)
		cout<<"arr2 == arr1\n";
	else
		cout<<"arr2 != arr1\n";

	Array arr3;
	arr3 = arr2++;
	cout<<arr3<<"\n";



	if(arr3 != arr1)
		cout<<"arr3 != arr1\n";
	else
		cout<<"arr3 == arr1\n";
}


int main() {
	test_Array();
	cout << "Bye\n";

	return 0;
}
