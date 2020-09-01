#include <bits/stdc++.h>
using namespace std;

class MyVector {
private:
	int *arr;
	int len = 100;

public:
	MyVector(int len, int default_value = 0) {
		this->len = len;
		this->arr = new int[len];

		for (int i = 0; i < len; ++i) {
			this->arr[i] = default_value;
		}
	}

	MyVector(const MyVector & another) {
		len = another.len;
		this->arr = new int[len];

		for (int i = 0; i < len; ++i)
			arr[i] = another.arr[i];
	}

	~MyVector() {
		delete[] this->arr;
	}

	int Get(int pos) {
		if (pos < len)
			return this->arr[pos];
		else {
			cout<<"Invalid access\n";
			return -1;
		}

	}

	void Set(int pos, int val = 0) {
		if (pos < len)
			this->arr[pos] = val;
		else
			cout<<"Invalid access\n";
	}
	
	int GetLen() {
		return len;
	}
};

int main() {
	MyVector v(10, 12345);
	MyVector v2(v);

	v2.Set(12000);



	return 0;
}
