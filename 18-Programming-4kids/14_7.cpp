#include<iostream>
using namespace std;

struct queue {
	int arr[100];
	int len;

	queue() {
		len = 0;
	}

	void add_end(int value) {
		arr[len++] = value;
	}
	void add_front(int value) {
		// Shift right
		for (int i = len-1; i >= 0; --i)
			arr[i+1] = arr[i];
		arr[0] = value;
		len++;
	}

	int remove_front() {
		int ret = arr[0];
		// Shift left
		for (int i = 1; i < len; ++i)
			arr[i-1] = arr[i];
		--len;
		return ret;
	}

	void print() {
		for (int i = 0; i < len; ++i)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}
};

int main() {
	queue my_queue;

	my_queue.add_end(10);
	my_queue.add_end(20);
	my_queue.add_end(30);
	my_queue.print();

	my_queue.add_front(1);
	my_queue.add_front(4);
	my_queue.print();

	cout<<my_queue.remove_front();

	return 0;
}
