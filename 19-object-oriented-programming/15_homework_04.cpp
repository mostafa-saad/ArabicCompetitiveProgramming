#include <bits/stdc++.h>
using namespace std;

class Array {
private:
	int size;
	int *ptr;

public:
};

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
