/*
 * 287B.cpp
 *
 *  Created on: Mar 29, 2014
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

typedef long long         ll;











/*
 * 1. Reading: Direct
 *
 * 2. Samples:
 * 		4 3:	we have 2 splitter. 2 and 3. Adding them. 2 + 3 and one will be out/in so 2+3-1 => 4
 * 		5 5:	We need 5 outs and one of splitters already 1-5 so simply use it => 1
 * 		8 4: 	we have 2, 3, 4 splitter. Adding them all: 2 + 3 + 4 -2 => 7 < 8. So answer is -1
 *
 * 	  Missed:
 * 	  	none
 *
 * 	  Especial:
 * 	  	if we just need one output => then no splitter needed => 0
 *
 * 3 - Input Properties
 * 		none
 *
 * 4- Constraints
 * 		So Big: Seems fake / BinarySch / MatrixPow => may be applied
 *
 * 5 - Processing
 * 		As input is big, intermediate and output needs too much careful	=> Use long long as possible
 */

















/*
 * Problem type:
 * 		minimization. Check minimization algorithms
 * 		seems observation problem..we need to discover some facts
 *
 * Observations
 * 		- Splitters are given as incremental sequence: 2 3 4...k
 * 		- Each time we connect 2 splitters, one is common so must be removed.
 * 		- Generally if we will connect M elements M-1 will be used for joining
 * 		- So # of splitters of (a, b, c, d, e) = a+b+c+d+e -4
 * 		- Given K splitters, max outlets are (2+3+4+....k) - k-1
 * 		- Using max outlets we could easily detect the impossible case
 * 			- If not the case, we either could cover N or not
 * 		- Let's think concretely
 * 			- if n = 37 and k = 11
 * 			- then we could have (2+3+4....11) - 9
 * 			- What if we subtracted 1 from each splitter to get rid of this 9
 * 			- (1+2+3...10)..this is 1 more over the answer, each 2 splitter remove 1 not 2
 * 			- Simply minimize n by 1
 * 			- that is: 	  (2+3+4....11) - 9 = N
 * 			= 			= (1+2+3...10) 		= N-1
 * 			- Let K = K-1 and N = N-1
 * 			- our problem now, given numbers from 1-k, could we find subset with sum = N
 * 				- DP guys know this is related to subset sum problem which could be solved with DP
 * 				- But constrains won't help anyway
 */

















/*
 * More analysis:
 *
 * 	- Let's think about our new problem: Given N, K: find subset with min # of items with sum = N
 * 		- if N = 36 and K = 10
 * 		- so we have 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 splitter outlets
 * 		- as we need the minimum, make sense to use 10 first. Now we need 26
 * 		- then 9 => 17. Then 8 => 9. Then 7 => 2. Next was 6, but it is bigger than 2
 * 		- As we have 6, then we must have 2
 * 		- Now, It is clear 3 things:
 * 			- If initially sum was >= N, then we must find a solution
 * 			- It make sense to start from the tail and get numbers till next is > reminder
 * 			- At this point of time, if u subtracted K elements, answer is K+1 if reminder > 0
 * 			- However, K = 10^9, we need faster way to simulate this.
 *
 */





















/*
 * One of algorithms that fit in our constrains in Binary Search. Could we use it?
 *		We need to define function and to make sure its curve is either: 0 0 0 0 1 1 1...1 OR 1 1 1 1 1 0 0 0 0 ..... 0
 *
 *	What is our function: Is using the last X elements and may be one extra element enough to cover N?
 *		e.g. in our example (N = 36 and K = 10) using last 4 elements and the 3 was enough as sum
 *
 *	Define function to be: F(p) = Sum of last P elements <= N
 *		if so, then they might be used
 *		as we want minimum elements we need p with maximum sum <= N
 */





























// sum: 1 2 3 ... n
ll sum(ll n)
{
	return (n * (n+1)) / 2;
}

// sum: s s+1 s+2 ... e
ll sum(ll s, ll e)
{
	if(s <= 1)
		return sum(e);

	return sum(e) - sum(s-1);
}

ll minSplitters(ll k, ll n)
{
	ll st = 1, en = k;

	while(st < en)
	{
		ll md = (st + en)/2;
		ll s = sum(md, k);

		if(s == n)
			return k - md + 1;

		if(s > n)
			st = md+1;
		else
			en = md;
	}

	return k - st + 2;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	ll n, k;
	cin>>n>>k;

	if(n == 1)
		cout<<0<<"\n";		// already just 1 out flow source exist
	else if(n <= k)
		cout<<1<<"\n";		// we have 1-n splitter already
	else
	{
		--k;
		--n;

		if(sum(k) < n)
			cout<<-1<<"\n";
		else
			cout<<minSplitters(k, n)<<"\n";
	}


 	return 0;
}
