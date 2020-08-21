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
	~MyVector() {
		delete[] this->arr;
	}
	int get(int pos) {
		return this->arr[pos];
	}
};

int main() {
	MyVector v(10, 12345);

	cout<<v.get(5);	// 12345


	return 0;
}
