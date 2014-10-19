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
How to evaluate order of recursive functions?
Linear Recursion Order
Logaritgmic Orders
Exponentials Orders
Divide and Conquer Order
Flood Fill Order
How to evaluate Sieve Algorithm Order


Links
http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=complexity2
http://en.wikipedia.org/wiki/Prime_number_theorem
http://en.wikipedia.org/wiki/Divergence_of_the_sum_of_the_reciprocals_of_the_primes
*/


const int MAX = 100;
int n;
bool valid(int i, int j) { 	return 1;	}
char maze[MAX][MAX];
bool vis[MAX][MAX];





























void SayIamTopCoder(int cnt)		//	O(n)
{
    if(cnt < 1)
		return;

    cout<<"I am  TopCoder.\n";

    SayIamTopCoder(cnt - 1);		// Just 1 recursive call
}















int F3n_1(int n)		// O( length(3n+1) )
{
	if(n == 1)
		return 1;

	if(n%2 == 0)
		return 1 + F3n_1(n/2);	// Either this call

	return 1 + F3n_1(3 *n + 1);	// or this call, but NOT Both
}












// What about other hard recursive function. let's revise some equations first.
















// How to evaluate? let's try RECURSION METHOD:
// Consider 1) number of operations per level	2) Maximum Height
// Evaluate summation of this order
//
// First order doesn't depend on a
//
//					k									Level 1: 1 operation
//		k/2					k/2-1						Level 2: 2 operations
//	k/4	   k/4-1		k/4-0.5		k/4-1.5				Level 3: 4 operations
//														Level 4: 8 operations
//														Level ?: Max level is when k/2/2/2=k/2^i = 1. Then Max = log k base 2
// We are doing 2^0 + 2^1+2^2...2^mx = (2^mx+1)-1.
// E.g. 2^0 + 2^1 + 2^2 = 1 + 2 + 4 = 7 = 2^3 -1
//
// mx = log(k)
//
// 2^mx+1 = 2^log(k)+1	and we know tha 2 ^ log(n base 2) = k
//
// Then  2^log(k)+1	= O(k)
//
ll sumPows(ll a, int k) { // Return a^1+a^1+a^2+.....a^k	in O(k)
	if (k == 0)
		return 0;

	if (k % 2 == 1)
		return a * (1 + sumPows(a, k - 1));

	ll half = sumPows(a, k / 2);
	return half * (1 + half - sumPows(a, k / 2 -1) );
}














// exponential: c^n (e.g. 2^n)

// generate all sequences of given length, of zeros and ones
// E.g. for len = 3:	000, 001, 010, 011, 100, 101, 110, 111
//
//								""												Count=1
//					0								1							Count=2
//			00 				01				10				11					Count=4
//		000		001		010		011		100		101		110		11				Count=8
//
//	SUM 2^i	= 2^n
void generateBinary(int len, string cur = "")	// O(2^n)	... O(Branching Factor ^ Depth)
{
	if(len == 0)
	{
		cout<<cur<<"\n";
		return;
	}

	// At each level, we branch twice...draw this tree
	generateBinary(len-1, cur + "0");

	generateBinary(len-1, cur + "1");
}











// generate all sequences of given length, of zeros, ones and two2
// E.g. for len = 2:	00, 01, 02, 10, 11, 12, 20, 21, 22
void generateTernary(int len, string cur = "")	// O(3^n)	... O(Branching Factor ^ Depth)
{
	if(len == 0)
	{
		cout<<cur<<"\n";
		return;
	}

	// At each level, we branch three times...draw this tree
	generateTernary(len-1, cur + "0");

	generateTernary(len-1, cur + "1");

	generateTernary(len-1, cur + "2");
}












int fib(int n)
{
	if(n <= 1)
		return 1;

	return fib(n-2) + fib(n-1);	// Exponential. Branching twice..We will have exponential number of nodes in last level
}





















// Print permutations
/*	for n = 4

			1						2				3				4					Level 1: 4 branches
 	2 		3 		4		1		3		4		1	2	4		1	2	3			Level 2: 4*3 branches
   3 4 	   2 4 	   1 3	   3 4     1 2													Level 3: 4*3*2 branches
   4 3     4 2																			Level 3: 4*3*2*1 Ending node

																						n! = 4! = 4*3*2*1
 */
void perm(int i, int n, int vis[], int cur[])		// O()
{
	if(i == n)
	{
		// print
		return;
	}

	for (int j = 0; j < n; ++j) if(!vis[j])
	{
		vis[j] = 1;
		cur[i] = j;

		perm(i+1, n, vis, cur);

		vis[j] = 0;
	}
}




















// Let n = high - low + 1, the number of elements to sort
// T(n) = T(n/2) + T(n/2) + n = 2 T(n/2) + n

// Say we need to sort array of 8 elements: 5 1 4 6 7 2 1 8

//									1 2 4 5 6 2 7 8												// Split to 2 * 4 items, do 8 merge steps
//			1 4 5 6												1 2 7 8							// Split to 4 * 2 items, do 8 merge steps
//		1 5						4 6						2 7					1 8					// Split to 8 * 1 items, do 8 merge steps
//	5				1	4					6	7					2 				1	8		// Base Case
//
//																								8/2/2/2 = 1. Height 8/2^k = 1. k = log8
//																								Then we do logn levels, and n operations per level
//																								n log n


void mergesort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int mid =(low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        // linearly, merge to sorted blocks			O(n)
    }
}
























// T(n) = n^3 + 3 * T(n/2)
// Level 1 we do: N^3
// Level 2 we do: 3/8 N^3
// Level 3 we do: (3/8)^2 N^3
// up to logn levels
//
// so we have N^3 (1 + 3/8 + (3/8)^2 + (3/8)^3 ....)
// What is this, geometric series: evaluated to 1 /  (1-x) = 1 / (1-3/8) = 5/8
// Then we do 5/8 N^3
//
// Then we are surprisingly, O(n^3)

int playRec(int n)
{
	if(n <= 1)	return 1;

	int cnt = 0;
	for(int i = 0 ; i < n; i+=2)
		for(int j = 2*i; i < n-1; ++i)
			for(int k = (i+j)/2; k < n; k++)
				cnt++;

	int a = playRec(n/2 - 0);
	int b = playRec(n/2 - 1);
	int c = playRec(n/2 - 2);

	return cnt + a + b + c;
}















/*
..
..


...x.
..x..
.x...
x....

 */
int cnt = 0;
void cntReachalbleCells(int r, int c)
{
    if( !valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
		return;		// invalid position or block position


	vis[r][c] = 1;	// we just visited it, don't allow any one back to it
	cnt++;

	// Try the 4 neighbor cells
	cntReachalbleCells(r, c-1);
    cntReachalbleCells(r, c+1);
    cntReachalbleCells(r-1, c);
    cntReachalbleCells(r+1, c);
}


// What about finding number of connected components?
void cntComponents(int R, int C)	// O(R*C)
{
	int comps = 0;

	for(int i = 0; i < R; ++i)
	{
		for(int j = 0; j < C; ++j)
		{
			cnt = 0;
			cntReachalbleCells(i, j);	// some times O(1)			-		O(cnt)

			if(cnt > 0)
				comps++;
		}
	}

}
















// Some times it got harder! And scientists keep working trying to give a good upper bound, e.g. GCD order!
// Let's try one hard order, Sieve algorithm





























void sieve(int n)
{
	vector<bool> isPrime(n+1, true);	// set all of them to primes
	isPrime[0] = isPrime[1] = 0;		// 0, 1 are not primes

    for (ll i = 2; i*i <= n; ++i) {					// For each prime in range
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)		// remove n / pi number
            	isPrime[j] = 0;
        }
    }
}


















// From Prime number theorem: what is count of primes in range N? what is ith prime number?
void primesApproximation()
{
	const int n = 100;
	int primelst[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; // [1-100]

	cout<<"Estimated primes in range 100: "<<ceil(n / log(n) )<<" - Correct are 25\n\n";			// n/ln(n)
	for (int i = 1; i <= 25; ++i)
		cout<<i<<"th prime is: "<<primelst[i-1]<<" and estimated: "<<ceil( i * log(i) )<<"\n";		// i lni
}




















// Again, what we are doing
// Let X = Sqrt(n)
// Let Y = # of primes in range X = X / ln(X)

// For each prime pi in the Y primes
	// Cross n / pi numbers

// operations 	= SUM {i in range [1 - Y]} n / pi
// 				= SUM {i in range [1 - Y]} n / i ln(i)
// n is common
// 				= n * SUM {i in range [1 - Y]} 1 / i ln(i)
//
// From Prime harmonic series [1-m] = 1/2 + 1/3 + 1/5 + 1/7 + 1/11 ...
//	SUM 1 / pi ~= ln ln m
//
// n * ln ln(Y)
// n * ln ln( X / ln(X) )
// n * (	ln ln(X) -  ln ln ln(X) )			// ln ln ln(X) is a very tiny number, as we are targeting upper bound, and it is subtracted, remove it
// n * ln ln(X)
// n * ln ln (sqrt(n))							// ln (a^b) = b ln(a)
// n * ln( 1/2 * ln(n) )
//
// n  * ln(1/2) + n ln ln(n)					// ln(1/2) is constant: = -0.693147
//
// Then sieve is O(n ln ln n)					// Note, ln ln n is double logarithmic, and its value is so tiny
//
// The above derivation is not be fully correct (e.g. ilni = 0 for i=1, so we need to get it first from summation SUM {i in range [1 - Y]} n / i ln(i)





















// Exercise 1: prove that in sieve code: j could start with i*i, instead of i*2
// Exercise 2: prove that using i*i doesn't enhance the asymptotic order.























