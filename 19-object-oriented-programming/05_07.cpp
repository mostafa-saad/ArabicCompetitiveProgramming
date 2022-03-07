#include <bits/stdc++.h>
using namespace std;

class MyVector {
private:
	int *arr;
	int len = 100;

public:
	MyVector(int len_, int default_value = 0) {
		len = len_;
		arr = new int[len_];

		for (int i = 0; i < len; ++i) {
			arr[i] = default_value;
		}
	}
	~MyVector() {
		delete[] arr;
	}
	int get(int pos) {
		return arr[pos];
	}
};

int main() {
	MyVector v(10, 12345);

	cout<<v.get(5);	// 12345


	return 0;
}
