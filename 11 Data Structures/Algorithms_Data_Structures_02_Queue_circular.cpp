#include <iostream>
using namespace std;
const int MAX_SIZE = 2;

class MyQueue {
private:
	int qu[MAX_SIZE], front, size;

public:
	MyQueue() {
		front = 0;
		size = 0;
	}
	void push(int data);
	int pop();
	bool IsFull();
	bool IsEmpty();
	void display();
};

void MyQueue::push(int d) {

	if(IsFull())
	{
		cout<<"Error: Complete queue\n";
		assert(false);
	}

	qu[(front+size)%MAX_SIZE] = d;
	++size;
}

int MyQueue::pop() {
	if (IsEmpty()) {
		cout << "\Error: Empty queue\n";
		assert(false);
	}

	int ret = qu[front];
	front = (front+1)%MAX_SIZE;
	size--;

	return ret;
}

void MyQueue::display() {
	while(!IsEmpty())
		cout<<pop()<<"\n";
}

bool MyQueue::IsFull() {
	return size == MAX_SIZE;
}

bool MyQueue::IsEmpty() {
	return size == 0;
}

int main() {
	MyQueue q;
	q.push(10);
	q.push(20);

	q.pop();
	q.push(30);

	q.display();



	return 0;
}
