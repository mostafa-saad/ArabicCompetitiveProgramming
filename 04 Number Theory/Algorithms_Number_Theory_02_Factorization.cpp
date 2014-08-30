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
What is Factorization?
Generating Divisors
Prime Factorization
Using Prime Factors to generate Divisors
Factorizing N ^ power
Range Divisors Sum: Forward / Backward thinking

exercises:
UVA: 10789, 583, 10650, 10699

Links
http://en.wikipedia.org/wiki/Factorization
http://en.wikipedia.org/wiki/Prime_factor

*/

#includeset
#includemap
#includelist
#includeiomanip
#includecmath
#includestring
#includevector
#includequeue
#includestack
#includecomplex
#includesstream
#includeiostream
#includealgorithm
#includestdio.h
using namespace std;
typedef long long ll;


int total_operations = 0;










 Factorization Decompose number to set of multiplied numbers
 300 = 4  3  25
 Fundamental theorem of arithmetic (unique-prime-factorization theorem) every integer  1 is either prime or product of primes
 7 is prime
 300 = 2  2  3  5  5 = 2^2  3^1  5^2




















vectorll generate_divisors(ll n)	 O( sqrt(n) )
{
	vectorll v;
	ll i;
	for(i = 1 ; ii  n  ;++i)
		if(n%i == 0)
			v.push_back(i), v.push_back(ni);

	if(ii == n)
		v.push_back(i);

	return v;	 Not sorted
}















 How to factroize n
 1) use Sieve to get prime numbers in range n
 2) For each prime p,
		while(n%p == 0)
			cnt++;
			n = p;

















 what about n = 0 n = 1
vectorll factorization(ll n) 	 max n is 1e12
{	 O( sqrt(n) )

	vectorll primes;

	for (ll i = 2; i  i = n; ++i)	 Improve start by i = 3.
		while (n % i == 0)
			primes.push_back(i), n = i;	 Get every prime inside n.	n  i^j	is a new number

	 Two ways to prove that n will be prime number if n  1
	 1) Think in n  pi^x as a NEW sub-problem. If we went to its sqrt and % applied, then we are facing a prime number
	 2) Prove that, for any n either all its primes before sqrt(n), or only the biggest prime after sqrt(n).
	if (n  1)
		primes.push_back(n);

	return primes;
}























 Counting the divisors
 2^4 has 5 divisors 2^0, 2^1...2^4
 p^n has n+1 divisors for any pprime number
 what about p1^a  p1^b  	(a+1)  (b+1)
 E.g. 12 2^2  3^1	has 3  2 divisors.
 12 = 2^0  3^0
 12 = 2^0  3^1
 12 = 2^1  3^0
 12 = 2^1  3^1
 12 = 2^2  3^0
 12 = 2^2  3^1
 So if we modified factorization to return (p1^a, p2^b...)
 We could develop a simple RECURSIVE code to build the divisors.
 Simply pick a power from current prime, and move to next prime number
 Any iterative code is also possible, but a bit challenging



















 what about Factorizing n^power
 Simply if 	n   = p1^a 		 p2^b 		 p3^c
 Then      	n^z = p1^az 	 p2^bz 	 p3^cz

 Divisors of 	n   = (a+1) 	 (b+1) 	 (c+1)
 Divisors of 	n^z = (az+1) 	 (bz+1) 	 (cz+1)

















 Let D(i) is number of divisors of i. Return sum D(i) in range n
int rangeFactorization1(int n)			 Forward thinking
{
	int s = 0;
	for (int i = 1; i = n; i++)
		s += generate_divisors(i).size();

    return s;
}




















int rangeFactorization2(int n)		 backward thinking
{	suitable for range 210^6
	vectorint numFactors(n+1);

	for (int i = 1; i = n; i++)			 For each divisor
		for (int k = i; k = n; k += i)			 For each divisble number
        	numFactors[k]++;						 i divides k

	int s = 0;
	for (int i = 1; i = n; i++)
		s += numFactors[i];		 sure you can do it without an array

    return s;
}


















// Could you do it using sieve for more efficient code





