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
Content:
1- Why do we measure algorithms performance?
2- Little Theoretical Background
3- Big O Notation
4- Examples for: Constant, logarithmic, linear, polynomial and exponential Order

Links:
http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=complexity1
http://en.wikipedia.org/wiki/Time_complexity
http://en.wikipedia.org/wiki/Big_O_notation
http://en.wikipedia.org/wiki/Best,_worst_and_average_case
http://en.wikipedia.org/wiki/Computational_complexity_theory
*/








// We need a way to "measure" algorithms performance, mainly time and memory
// If we did so, we could "compare" algorithms

// Shortcomings of empirical metrics (e.g. record run time of an algorithm in table and compare) - Machine dependent

// What about evaluating number of steps in an algorithm.
// E.g. 1st statement: N time, 2nd is 2*N, third is 5N^2, then we are: N + 2N + 5N^2 ....  not practical

// Worst, Average, and Best-case Complexity
// Worst-case / Average-case Complexity are not practical. average input means? probabilities of a case?

// Most of time, we are interested algorithm behavior in the worst possible case (some times average e.g. quicksort)
















// Asymptotic Complexity: Running time of an algorithm 		as a	 function of input size n for 		large n.
// Big O notation, Gamam and Theta. Big O is the most popular and practical.


// Big O notation is a convenient way to express the worst-case scenario for a given algorithm
// although it can also be used to express the average-case
// Big O notation is an "asymptotic upper bound" on the growth rate of a function.

// G(x) is O(F(x))		(E.g. Sorting algorithm is 2 n^2 operation: 	G(x) is Sorting algorithm and F(x) is n^2
// IFF we could find: n0 < n & constant c such that G(x) < c * F(x)
// We call c the hidden constant
//
// E.g. Let G(x) = N + 2N + 5N^2, we say it is O(N^2)
// As we could find N0 = 2, and C = 6 such that: N + 2N + 5N^2 < 6 n^2

// If an algorithm is O(N2), it is also O(N^3),  O(N^4 logN)...and any higher order

// Remember, it is just an upper bound, we could write 2 codes both are O(n^2)...first has c = 5 and second has c = 300

// Let's study family of orders: E.g. Constant, logarithmic, polynomial, exponential ...



















// Constant Order
// O(1)
void ConstantOrder1()
{
	int start = 6;
	int end = 100;

	int mid = (end - start) / 2;

	if(mid%2 == 0)
		--mid;
}

void ConstantOrder2()
{
	int start = 7;
	int end = 0;

	// As long as, operations are not controlled by "VARIABLE", they are CONSTANT
	for (int i = 0; i < 1000; ++i)
		end += end * 2 + start;
}





















// double logarithmic: Log Log N
// This is extremely small value: E.g Log Log (1000000) = Log 6 = 1			in log base 10
// Rare algorithms use this order: E.g.  interpolation search & Sieve




























// logarithmic: log(n)
// Very Popular

void logn1()
{
	int n = 1048576;

	int steps = 0;
	while(n > 1)
	{
		// Do some constant operations
		n /= 2;
		steps++;
	}
}


void logn2(int val)
{
	// Fill array with 1000000 sorted number
	vector<int> v;
	for (int i = 0; i < 1000000; ++i)
		v.push_back( rand() );
	sort(v.begin(), v.end());

	// Search for value in a sorted array
	int start = 0, end = 1000000-1;
	bool found = 0;

	// Binary Search
	while(start < end)
	{
		int mid = (start+end) / 2;	// mid of range

		if(v[mid] == val)
		{
			found = 1;
			break;
		}

		// Shring half range per step
		if(val < v[mid])
			end = mid-1;
		else
			start = mid+1;	// then value must be in the other side
	}
}













// Fractional power: E.g. sqrt(n)

void sqrtn()
{
	// Fill array with 1000000 sorted number
	vector<int> v;
	int n = 1000 * 1000;
	for (int i = 0; i < n; ++i)
		v.push_back( rand() );
	sort(v.begin(), v.end());

	int m = sqrt(n);	// divide array to sqrt(n) blocks

	vector<int> min(m);
	vector<int> max(m);

	for (int i = 0; i < m; i += m) {	// for each block: we have sqrt n block
		// divide data to blocks of sqrt length

	}
}















// Linear O(n)
void linear1()
{
	int n = 10000;
	for(int i = 0; i < n; i++)
	{
		ConstantOrder1();
		ConstantOrder2();
	}
}

// Linear O(n)
void linear2()
{
	int n = 10000;
	for(int i = 0; i < n; i++)
		ConstantOrder1();

	for(int i = 0; i < 5*n; i++)
		ConstantOrder1();

	// O(n) + O(5n) = O(n) ... drop any constants
}




















// loglinear: O(nlogn)
void loglinear1()
{
	int n = 1000;

	for (int i = 0; i < n; ++i) {	// n step
		logn2(i);					// each step log n
	}
}























// polynomial: O(n^c) where c > 1. E.g.		O(n^2)..O(n^5)

void nPow2_1()	// O(n^2)	= Quadratic
{
	int n = 1000;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cnt++;
		}
	}
}


void nPow2_2()	// O(n^2)
{
	int n = 1000;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			cnt++;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 1000; ++k) {
				cnt++;
			}
		}
	}

	// (n * (n+1)/2) + 10000 n^2 = O(n^2)
}
















void nPow3_1()	// O(n^3)	cubic
{
	int n = 1000;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				cnt++;
			}
		}
	}

	// Expected 1000,000,000 operations
}


void nPow3_2()	// O(n^3)	cubic
{
	int n = 1000;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			for (int k = j; k < n; ++k) {
				cnt++;
			}
		}
	}

	cout<<cnt;
	// Expected 167,167000 operations
}













// factorial: O(n!)
void factorialn1()
{
	string str = "abcd";	// iterate over all permutations

	do {
		cout<<str<<"\n";
	} while(next_permutation(str.begin(), str.end()));
}














void what_is_my_tight_Order()	// ?
{
	const int n = 15;
	int arr[n] = {4, 4, 4, 5, 5, 5, 5, 5, 9, 11, 11, 13, 13, 16, 18};


	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = i; j < n && arr[i] == arr[j]; ++j) {
			cnt++;
		}
		cout<<arr[i]<<" appeared "<<cnt<<" times\n";
		i = i + cnt - 1;
	}

	// It is O( n )
}










// What about algorithm memory order?

void memory()
{
	// We check memory size relative to n

	int n = 100;
	vector<int> v1(n);		// O(n)

	vector< vector<bool> > v2(n, vector<bool>(20));	// O(n)



	int a = 1, b = 2, c = a+b;	// O(constant)

	const int MAX = 15;
	int arr1[MAX][MAX][MAX];	// O(n^3)


	char arr2[n][(int)log(n)];	// O(nlog(n))

	string str = "abcdef";		// O(length)

	vector<string> vstr(n);		// O(length * n)
}



/*
 	 Estimate of Max N against an order to be used in contest (differ from Online Judge to another)

				complexity		maximum N
				O(log(n))		10^18
				O(N)			100 000 000
				O(N log N)		40 000 000
				O(N2)			10 000
				O(N3)			500
				O(N4)			90
				O(2^N)			20
				O(N!)			11
*/
