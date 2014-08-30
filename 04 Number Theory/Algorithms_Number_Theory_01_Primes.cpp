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
Basic:
This is an Arabic Series in Algorithms, but mainly oriented toward Programming Competitions like ACMICPC and TopCoder. We start it in primes.

Content:
1- What is prime number? Some facts
2- A general purpose algorithm for Primality Test
3- Counting primes in range using Sieve Algorithm
4- Thinking technique: Forward Thinking Vs Backward Thinking
5- Tips & Tricks: Algorithm Order Vs Exact number of operations

Links:

http://en.wikipedia.org/wiki/Prime_number
http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/


int total_operations = 0;











// Facts
// int primelst[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; // [1-100]
// (2^31)-1 is a prime number with value 2147483647
// (2^61)-1 is a prime number with value 2305843009213693951
// primesRangeCnt 10^i (4, 25, 168, 1229, 9592, 78498, 664579, 5761455) [e.g. 4 primes <= 10^1] ~= n / log(n)
// 257, 263, 269, 271 -> 4 primes their multiplication > 2^32
// Wilson's theorem: (p-1)!%p = p-1 IFF p is prime













typedef long long ll;

bool isprime1(ll n) {		// O(n)
    if(n == 2) 	return true;
    if(n < 2) 	return false;

    for(int i=2; i < n; i++)
    	if(n%i == 0)
    		return false;
    return true;
}












bool isprime2(ll n) {		// O(n)
    if(n == 2) 	return true;
    if(n < 2 || n%2 == 0) 	return false;

    for(int i=3; i < n; i+=2)
    	if(n%i == 0)
    		return false;
    return true;
}













// 36 = 1 * 36
// 36 = 2 * 18
// 36 = 3 * 12
// 36 = 4 * 9
// 36 = 6 * 6
// 36 = 9 * 4
// 36 = 12 * 3
// 36 = 18 * 2
// 36 = 36 * 1
// if n = a * b and a <= b		THEN	a <= sqrt(n)	and 	b >= sqrt(n)
// why trying after sqrt if before it is enough?
bool isprime3(ll n) {	// O( sqrt(n) ? NO
    if(n == 2) 				return true;
    if(n < 2 || n%2 == 0) 	return false;

    for(ll i=3; i <= sqrt(n); i+=2)
    	if(n%i == 0)
    		return false;
    return true;
}















// i <= sqrt(n)		power 2 sides
// i * i <= n		Integer version
bool isprime4(ll n) {	// O( sqrt(n)
	total_operations++;
    if(n == 2) 				return true;

    total_operations++;
    if(n < 2 || n%2 == 0) 	return false;


    for(ll i=3; i*i <= n; i+=2)
    {
    	total_operations++;
    	if(n%i == 0)
    		return false;
    }
    return true;
}
























// Return number of primes in range n
int countPrimesInRange(int n)	// Forward thinking
{	// O(n * sqrt(n) )
	total_operations = 0;
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if( isprime4(i) )
			++cnt;

	return cnt;
}






















// 2, 3, , 5, , 7, , , ....
// Let 2 removes 4, 6, 8, 10.....n
// Let 3 removes 6, 9, 12, 15....
// 4 is removed
// let 5 remove 10, 15, 20.....
// 6 is removed
// could 7 be removed? NEVER, no one before it could divides it!
// Let 7 removes 14, 21 ...
// Do we need to work more than sqrt(n)? No


int countPrimesInRange_sieve(int n)	// Backward thinking
{
	vector<bool> isPrime(n+1, true);	// set all of them to primes
	isPrime[0] = isPrime[1] = 0;		// 0, 1 are not primes

    for (ll i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)
            	isPrime[j] = 0;
        }
    }

    int cnt = 0;

    for (int i = 0; i < (int)isPrime.size(); ++i)
    	if(isPrime[i])
    		cnt++;

    return cnt;
}















void twoloops1(int n)	// O(n^2)
{
	total_operations = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// some logic
			++total_operations;
		}
	}

	cout<<total_operations<<"\n";
}

void twoloops2(int n)	// O(n^2)
{
	total_operations = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			// some logic
			++total_operations;
		}
	}

	cout<<total_operations<<"\n";		// (n * (n+1) )/2
}




















void threeloops1(int n)	// O(n^2)
{
	total_operations = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				// some logic
				++total_operations;
			}
		}
	}

	cout<<total_operations<<"\n";
}

void threeloops2(int n)	// O(n^3)
{
	total_operations = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			for (int k = j; k < n; ++k) {
				// some logic
				++total_operations;
			}
		}
	}

	cout<<total_operations<<"\n";		// has known formula
}















