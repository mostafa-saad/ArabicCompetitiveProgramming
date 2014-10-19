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
What is Factorial? Some Facts
How to implement it for big numbers?
Number of factorial digits? bits?
Given n and Prime p, what is max x such that n! % p^x = 0
Factorial Factorization
Given m & n, what is max x such that m^x % n! = 0
How to calculate gcd(!m, n)
How many trailing zeros in n!?
What is right most non zero digit of factorial N?

Exercises: UVA (160, 324, 10139, 568, 623, 884, 10323)

Links:
http://en.wikipedia.org/wiki/Factorial
http://blmath.wordpress.com/2009/04/27/prime-factorization-of-factorials/
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
#define all(v)				((v).begin()), ((v).end())
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




























// Facts
// Fact(n) = 1 * 2 .... n
// Fact(0) = Fact(1) = 1
// Implemented iteratively and recursively
// Factorial is exponential: so be careful either in: computation or algorithm order
// n! % x	where x <= n	-> 0
// Wilson's theorem: (p-1)!%p = p-1 IFF p is prime
// 2! is the only prime factorial












// What about implementing a big factorial? e.g. 500!
// Overflow. Use Big integers...or just simplified code (we just need *)
// Create a vector of max length expected
// Intialize it to 1
//
// From i = 2 to N
//		Multiply i in every cell
//		For every cell, if its value > 9, handle its carry (v%10, v/10)
//		For last cell, check if it has carry (typically will have), and put it in next cell, AS LONG AS there is a carry
//










// Number of factorial digits?
// how many digit for 1000? 1050? 9000 ? 9999? 4 digits. Use 1 + (int)log10(n)
// pow(10, log10(X) ) = X
// log(a*b) = log(a)+log(b)
// Then: log(n!) = log(1) + log(2) .... log(n)
// What about log(0!) ?

// What about number of bits for factorial? Think as above. Remember, 8 needs only 4 bits















// Given a prime p, and n!, what is max x such that n! divisble by p^x

// For each multiple M of p <= n:		1*p, 2*p, 3*p...			n/p times
// while n%p != 0
// 	cnt++
//	n /= p;
//
// Order: O(n/p)










/*
			  1				 	  2
	  1	  	  2		   3		  2
  1	  2   3	  2   5	   2    7	  2
1 2	3 2 5 2 7 2 9 2 11 2  13 2 15 2				[Exploring 16! with p=2]




																						1			2
													1					2				5			5
		1		  2				   3	  4			5	  6				5				5			5
1 2 3 4 5 6 7 8 9 5    11 12 13 14 15 ... 20	..	5 ... 5	...			5				5			5			.... [Exploring 500! with p=5]
*/













// Very important function
int FactN_PrimePower(int n, int p) {		// O(log(n) base p)
    int pow = 0;
    for(int i = p; i <= n ; i = i * p)
    	pow += n/i;

    return pow;
}















// Factorial Factorization: n! = p1^a * p2^b ...
// What are possible primes in n!? Factorial is exponential, but finally it consist of [1-n]
// So primes in range n

// Seive on n, get primes in range n
// For each prime number p
//	call FactN_PrimePower(n, p)



















// Given m, what is max x such that m^x divides n!?
// Again, think in prime representation.
// let's simplify, uch that m^x divides g?
// Let m =  2^3 * 5^4
// Let g =  2^10 * 5^8 * 11^3
// Then 1st we can with 2 and 5 only.
// 10/3 = 3, then max for p1=2 is (2^3)^3
// 8/4 =2, so max is (5^4)^2
// Then let x = min(3, 2) = 2...so m^2 divides g
//
// what if m = 2^3 * 5^4 * 7^2 ? then it doesn't divide g, and x = 0
//
// what about n!?
// Then factroize m
//	for each p^x in m
//		check power in n!, and follow as above


















// What about calc gcd(!m, n)
// gcd is greatest common divisor
// Let m =  2^3 * 5^7
// Let n =  2^10 * 5^3 * 11^3
// then gcd is min of each power, so that it divides both, and largest
// gcd = 2 ^ min(3, 10) * 5 ^ min(7, 3) * 11 ^ min(0, 3)
//
// Then factroize n
//	for each p^x in n
//		check power in m!, and use min of powers






















// How many trailing zeros in n!?	E.g. 15! = 1307674368000	-> 3 zeros
// How to calculate them? How zero come in base 10? 2*5
// Then, if w know that n! = 2^a * 5^b * reminder...then we have min(a, b) zeros.
// More simpler, count of 2s > count of 5s in n!...then min(a, b) = b always
// What about n! base X? how many zeros?
// Again, Let X = 16 (hexidecimal), when zero appears?...notice (10 in base 16 equals 16 in base 10)
// Again, every time n! has X, we have a nother Zero
// So how many Xs there in n!?
// Factorize X, check its primes power in n!

























// Get right most non zero digit of factorial N? So in 15! will be 8
// Let's simplify. Last digit of X = X%10
// Let X = 123000, then last non zero digit of X = 3
// Let X = 123 * 10^3, so 3 = 123%10
// Note (a*b*c)%D = (a%D * b%D * c%D) % D

// If in n! we could represent it as = 10^x * reminder...then reminder%10 is the answer
// again, Let n! = 2^a * 5^b * reminder1
// Then	n! = 10^b * reminder2

// So to calculate reminder2 we need to cacl n! such that we don't consider b 2's and b 5's
// In fact, all 5's wont't be used, and we will use overall a-b 2's

// Let n = 15, n! = 1307674368000 = 2^11 * 5^3 * 5108103
// So n! has 3 zeros
// We want to calculate n! with only 11-3 2's
// Let X = 2^8 * 5108103 = 1307674368		so X%10 = 8



// Exercise: Given M, How to get Smallest N, such that N! has M Trailing Zeros?





















