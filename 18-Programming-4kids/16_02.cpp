#include<iostream>
#include<deque>
using namespace std;

void print_back(deque<int> q) {
	cout << "Queue elements (back): ";
	while (!q.empty()) {
		cout << q.back() << " ";
		q.pop_back();
	}
	cout << "\n";
}

void print_front(deque<int> &q) {
	cout << "Queue elements (front): ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop_front();
	}
	cout << "\n";
}

int main() {
	deque<int> q;
	q.push_back(20);	// q: 20
	q.push_back(30);	// q: 20 30
	q.push_back(40);	// q: 20 30 40
	q.push_front(10);	// q: 10 20 30 40
	q.push_back(50);	// q: 10 20 30 40 50
	q.push_front(0);	// q: 0 10 20 30 40 50

	print_back(q);		// 50 40 30 20 10 0
	print_front(q);		// 0 10 20 30 40 50
	print_front(q);		// NONE

	return 0;
}
