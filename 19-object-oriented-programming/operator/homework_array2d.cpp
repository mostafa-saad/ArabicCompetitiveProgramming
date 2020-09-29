#include <bits/stdc++.h>
using namespace std;

class Array {
private:
	int size;
	int *ptr;

};

class Array2D: public Array {
private:
	int rows;
	int cols;

public:
	
};


void test_Array2d() {
	Array2D arr1(2, 3);

	int counter = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			arr1(i, j) = counter++;
		}
	}

	cout<<arr1<<"\n";

	Array2D arr2 = ++arr1;	// copy
	cout<<arr2<<"\n";

	if(arr2 == arr1)
		cout<<"arr2 == arr1\n";
	else
		cout<<"arr2 != arr1\n";

	Array2D arr3;
	arr3 = arr2++;
	cout<<arr3<<"\n";



	if(arr3 != arr1)
		cout<<"arr3 != arr1\n";
	else
		cout<<"arr3 == arr1\n";
}

int main() {
	test_Array2d();
	cout << "Bye\n";

	return 0;
}
