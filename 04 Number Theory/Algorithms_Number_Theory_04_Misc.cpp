/*
 *
 *
 ******************************************** Licence *******************************************
 * 																								*
 * This File is part of Algorithms Arabic Video Series											*
 *	Made By Eng Mostafa Saad, Teaching Assistant in FCI - Cairo University						*
 * 																								*
 *	Available at My YouTube Channel: http://www.youtube.com/user/nobody123497?feature=mhee		*
 * 																								*
 * Feel free to make use of it at anytime, for any reason, in anyway, without any obligations.	*
 * 																								*
 * 																								*
 * In case of finding a mistake, kindly notify me at: mostafa.saad.fci@gmail.com				*
 * 																								*
 * Mostafa Saad Ibrahim © 2013																	*
 * 																								*
 ************************************************************************************************
 *
 *
 */
 
 
 /*
Content
1- Fibonacci
2- GCD & LCM
3- Permutations & Combinations
4- Stirling & Bell Numbers
5- Calc: a^p
6- Calc: a^1 + a^2 + .... a^p

Download Equations Sheet (not remember its source): http://dl.dropbox.com/u/14991955/MathEquSheet.pdf

Problems: UVA(10368, 369, 412, 11000, 11417, 10229, 10892, 11388, 10717)

Links
http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=combinatorics
http://en.wikipedia.org/wiki/Fibonacci_number
http://oeis.org/A000045
http://en.wikipedia.org/wiki/Greatest_common_divisor
http://en.wikipedia.org/wiki/Euclidean_algorithm
http://en.wikipedia.org/wiki/Least_common_multiple
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
#include<algorithm>
#include<stdio.h>
using namespace std;
typedef long long ll;
#define aint(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair









#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;












// 	Fibonacci numbers: F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1

int fib(int n)
{
	if(n <= 1)
		return n;

	return fib(n-1) + fib(n-2);
}

void iterativeFib()
{
	int a = 0, b = 1;
	for (int i = 2; i < 10; ++i) {
		int c = a+b;
		a = b;
		b = c;
	}
}

long long Fib[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
	1597, 2584, 4181, 6765,  10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
	514229, 832040, 1346269, 2178309, 3524578,  5702887, 9227465, 14930352, 24157817,
	39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733,
	1134903170, 1836311903};

// Fibonacci: Exponential growth.
// Many facts in The On-Line Encyclopedia of Integer Sequences: 	http://oeis.org/A000045








// GCD: Greatest Common Divisor
// gcd(45, 10) = 5	then 45%5 = 10%5 = 0		and can't find n > 5 such that  45%n = 10%n = 0
//
// only? any more facts? NO
// if a%n = 0 & b%n = =0	THEN (a+b)%n = 0	and (a-b)%n = 0		as (a+b)%n = (a%n+b%n)%n = (0+0)%n = 0
// THEN
// gcd(45, 10) = gcd(35, 10) = gcd(25, 10) = gcd(15, 10) = gcd(5, 10) = 5
// gcd(10, 5) = gcd(5, 5) = gcd(5, 0) = 5
//
// Then we found an algorirthm!
//		function gcd(a, b)
//			if a = 0
//			   return b
//			while b ? 0
//				if a > b
//				   a := a - b
//				else
//				   b := b - a
//			return a
//
// Wait: We just keep reaming the small from the big, the big number turn to be the smaller, and then do reverse
// How to do this switch fast? gcd(45, 10) = gcd(45%10, 10)	-> simply remove aint the smaller cycles in 1 step
// Then code easily became


int gcd(int a, int b) {
	if(b==0)
		return a;
	return gcd(b, a%b);
}



// What about LCM: Least common multiple
// That is the first multiple of the 2 numbers.
// Let's do some prime representation for numbers a, b
// a = 2^3 * 7^6
// b = 2^5 * 7^2
//
// to get gcd, we need min of powers of 2 and min of powers of 7
// gcd = 2^min(3, 5) * 7^min(6, 2)
//
// what about lcm? we need max
// lcm = 2^max(3, 5) * 7^max(6, 2)
//
// given a, b, and gcd(a, b) how to get lcm(a, b)
//
// what about 		a*b = 2^(3+5) 		* 7^(6+2)
// and we know that gcd = 2^min(3, 5) 	* 7^min(6, 2)
//
// then lcm = a*b / gcd.














// Permutations: of set of objects: is an arrangement of those objects into a particular order.
// order does matter
// E.g. for set{1,2,3}, namely (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2), and (3,2,1) -> 3!	-> n!
//
// How? The rule of product
// First step we do n choices, in 2nd step, we are allowed only n-1, third n-2
// Then we have n * n-1 * n-2 ... 1 ways =		p(n) = n!
//
// what if we need arrangement of r elements. Same way: n x (n-1) x (n-2) x .....x (n- r + 1)
// P(n, r) = n! / (n-r)!
//
// Or think in another way: it is how many combination of r elements, and for each element do r! permutations
// That is it: P(n, r) = C(n, r) * r!
//
// what about Permutations with Repetition? Then always could select what do you want pr(n) = n^n

// Combinations: The number of ways of picking r unordered elements out of n elements
// order does not matter
//
// How to calculate?
// P(n, r) = C(n, r) * r!
// n! / (n-r)! = C(n, r) * r!
// C(n, r) = n! / ( (n-r)!  * r!)
//
// Also writing a recurrence is easy
//
// Let's do some evaluations
// C(1000, 2) = 499500
// C(1000, 999) = C(1000, 1) = 1000
// C(66, 33) = 7219428434016265740
// C(68, 34) = Overflow in long long
// watch out, based on cancellation of factorials, we could have small or big value.






// Many important and interesting functions to know

// Stirling numbers of the first kind: number of permutations of n elements with k permutation cycles

// Stirling numbers of the second kind: number of ways to partition a set of n elements into k groups.
// E.g. set{1, 2, 3, 4, 5} can be partioned to {1, 3, 5} {2, 4}

// Bell Numbers: number of partitions of a set of size n
// E.g. set{1, 2, 3, 4} can be divided {{1}, {3,2, 4}} or {{2, 4} {1, 3}}
// NOTE: partitions {{1, 2},{3, 4}} and {{3, 4}, {2, 1}} are counted once. NO ORDER ISSUES






















// How to calc 5^3?	Simple, loop 3 times, multiple 1 times 5		O(power)


// Divide and Conquer
// 10^16 = (10^8)^2
// 10^17 = (10^8)^2 * 10
int pow(int b, int p) {			// O(log(p) base 2)
	if(p == 0)	return 1;
	int sq = pow(b, p/2);
	sq = sq*sq;

	if(p%2 == 1)
		sq = sq*b;

	return sq;
}


// What about calculating: (a^1+a^2+a^3+a^4+a^5+a^n) ???

// Let's try even power
// (a^1+a^2+a^3+a^4+a^5+a^6) 	   = (a^1+a^2+a^3)+(a^1*a^3+a^2*a^3+a^3*a^3)
// (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+a^3)
// (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+ a^1+a^2+a^3 - (a^1+a^2))
//

// what about odd n
// (a^1+a^2+a^3+a^4+a^5+a^6+a^7)   = a + a*(a^1+a^2+a^3+a^4+a^5+a^6)
//								   = a(1+(a^1+a^2+a^3+a^4+a^5+a^6))


ll sumPows(ll a, int k) { // Return a^1+a^1+a^2+.....a^k	in O(k)
	if (k == 0)
		return 0;

	if (k % 2 == 1)
		return a * (1 + sumPows(a, k - 1));

	ll half = sumPows(a, k / 2);
	return half * (1 + half - sumPows(a, k / 2 -1) );
}

