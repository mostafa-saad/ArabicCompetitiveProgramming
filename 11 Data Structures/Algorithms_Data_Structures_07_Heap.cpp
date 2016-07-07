/*
 * heaps.cpp
 *
 *  Created on: Jan 15, 2014
 *      Author: Mostafa Saad
 */

#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)





















class PriorityQueue {

private:
	vector<int> heap;

	int left(int node);
	int right(int node);
	int parent(int node);
	void reheapUp(int pos);
	void reheapDown(int pos);

public:
	int top();
	void push(int key);
	void pop();
	void print();
	int size();
};






















int PriorityQueue::size() {
	return heap.size();
}

void PriorityQueue::print() {
	copy(all(heap), ostream_iterator<int>(cout, " "));
	cout<<"\n";
}






int PriorityQueue::top() {
	if (size() == 0)
		assert(false);

	return heap.front();
}


void PriorityQueue::push(int key) {
	heap.push_back(key);
	reheapUp(sz(heap) - 1);
}


void PriorityQueue::pop() {
	if (size()) {
		heap[0] = heap.back();
		heap.pop_back();
		reheapDown(0);
	}
}
















int PriorityQueue::parent(int node) {
	return node == 0 ? -1 : (node - 1) / 2;
}

int PriorityQueue::left(int node) {
	int p = 2 * node + 1;

	return p >= sz(heap) ? -1 : p;
}

int PriorityQueue::right(int node) {
	int p = 2 * node + 2;

	return p >= sz(heap) ? -1 : p;
}















void PriorityQueue::reheapUp(int in) { // we could also implement iteratively
	if (in == 0 || heap[parent(in)] < heap[in]) // stop when parent is smaller
		return;

	swap(heap[in], heap[parent(in)]);
	reheapUp(parent(in));
}






void PriorityQueue::reheapDown(int in) {
	int selChild = left(in);

	if (selChild == -1) // no children
		return;

	int rightChild = right(in);

	if (rightChild != -1 && heap[rightChild] < heap[selChild]) // is right smaller than left?
		selChild = rightChild;

	if(heap[in] > heap[selChild])
	{
		swap(heap[in], heap[selChild]);
		reheapDown(selChild);
	}
}
















int main() {
	PriorityQueue h;

	h.push(1);
	h.push(13);
	h.push(5);
	h.print();
	h.pop();
	h.print();

	return 0;

}
