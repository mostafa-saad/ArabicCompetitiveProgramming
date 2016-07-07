#include <iostream>
using namespace std;


const int MAX_SIZE = 5;

class queue {
private:
	int *qu, front, rear;
public:
	queue() {
		front = -1;
		rear = -1;
		qu = new int(MAX_SIZE);
	}

	void push(int data);
	int pop();
	bool IsFull();
	bool IsEmpty();
	void display();
};

void queue::push(int d) {
	if (IsFull()) {
		cout << "\nNo more memory\n";
		exit(1);
	}
	qu[++rear] = d;
}

int queue::pop() {
	if (IsEmpty()) {
		cout << "\nQueue is empty\n";
		exit(1);
	}
	return qu[++front];
}

bool queue::IsFull() {
	return rear == MAX_SIZE - 1;
}

bool queue::IsEmpty() {
	return rear == front;
}

void queue::display() {
	while(!IsEmpty())
		cout<<pop()<<"\n";
}

int main() {

	queue q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	q.display();

	return 0;
}
