#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
	vector<int> ret;

	if ((int)nums.size() < k)
		return ret;

    multiset<int> st;
    for (int i = 0; i < k; ++i) {
		st.insert(-nums[i]);
	}
    ret.push_back(-*st.begin());

    for (int i = k; i < (int)nums.size(); ++i) {
    	st.erase(st.find(-nums[i-k]));
    	st.insert(-nums[i]);
    	ret.push_back(-*st.begin());
	}
    return ret;
}

// https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sliding-window-maximum.cpp
// Very elegant faster solution, but harder to understand
// Key idea is to make always front of deque is index of current maximum
// Any time u add number, remove any previous number can't be the answer
// let's say [1 7 3 2 5]
// We enter 1, so fine
// Enter 7. Now, 1 never be an answer. so remove it
// Enter 3: notice when 7 removed, maybe 3 is answer
// Enter 2: notice when 7 & 3 removed, maybe 2 is answer
// Enter 5: now 3 2 never be answer, so remove them ==> [7, 5]
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    vector<int> ret;
    deque<int> dq;	// of indices for current window
    for (int i = 0; i < (int)nums.size(); ++i) {
        // Make sure ONLY k items in the deque
    	if (!dq.empty() && i - dq.front() == k)
            dq.pop_front();

    	// Remove any number that never to be the answer
    	// Any number lower than current number can't be answer
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)	// answer always in front
        	ret.push_back(nums[dq.front()]);
    }
    return ret;
}

int main() {

	vector<int> a = {1,3,-1,-3,5,3,6,7};
	a = maxSlidingWindow1(a, 3);

	for (int x : a)
		cout<<x<<" ";

	return 0;
}
