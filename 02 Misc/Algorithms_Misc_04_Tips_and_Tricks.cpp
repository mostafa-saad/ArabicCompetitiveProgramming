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
Char Grid Conversion
Ranges Intersection / Union
Array Flatten
Modulus
Math Operations Tricks
Dir Arrays
Memset in vis array trick
Checking Overflow
Output Overflow handling
Intermediate Overflow handling
Compressing Array of Numbers








-------------------------------------------------- Grid Conversion -------------------------------------------------------------------

Say we are given grid of characters, and you want to convert them to grid of numbers.
	Say you are given characters S, E, ., #		to {.=0, S=1, E=2, #=3}

...S.				00010
##E.#		->		33203
...#.				00030

	for(int i = 0; i < r; i++)
		for(int j = 0 ; j < c; j++)
			gridInt[i][j] = string(".SE#").find( gridChar[i][j] );		// order string according to your needs. No if else any more






























------------------------------------------------------------- Ranges Intersection / Union --------------------------------------------------------
Say you have 2 ranges [1-20] and [5-15]
	and want to find their Intersection? Union?

	Let them (a, b) and (c, d)

	1- check if no intersection is easy? I am after you or reverse
	if(b < c || d < a) ...

	2- Sort 4 numbers a, b, c, d

	3- Intersection: 2 numbers in mid.

	4- Union: 2 numbers on boundary




























---------------------------------------------------------Array Flatten------------------------------------------------------------
Say we have 2D array R*C, and we want to convert it to 1D array of R*C elements

	then for any (i, j) zero based: we have i rows before us, each of C elements. In current row, j elements.
	then (i, j) = i * C + j			(note j < C)

	what if we have index X in 1 D, and want to convert it to its 2D?
	we know X = i * C + j
		then X%C = (i * C % C + j % C)%C = j
			 X/C = i*C / C + j/C = i


What about X*Y*Z?

	Then (i, j, k) = i * Y * Z + j * Z + k	-> Each term * Multiplication of next dimensions

	What about Index?
		You have 2 ways: Think left or right?

	From Right?
		Index%Z = i * Y * Z + j * Z + k = 0 + 0 + k
		Index/Z = i * Y + j + 0		= Index2

		then
			Index2%Y = 0 + j
			Index2/Y = i

	From left
		Index % (Y*Z) = 0 + j*Z + k
		Index / (Y*Z) = i + 0 + 0

		and so on

	Coding wise, the processing from left and ranking (i, j, k) are similar






















-------------------------------------------------- Modulus -------------------------------------------------------------------
	 the remainder of division of one number by another
	 a % b = a - b * [a/b]		-> sometimes problem solution depends on the equation
	 7 % 3 = 3 - 3 * 2 = 1

	 Distributive Property over +, -, *
		(a+b+c)%X = (a%X + b%X + c%X)%X			REMEMBER the last %X

	What about negative a?
			postiveMode = (a%X + X)%X		-> get smallest negative, add 1 cycle, MOD again

	MOD is expensive! That is, in case a tight order problem, code TLE due to MOD!

		if(a > MOD || a < 0)	do MOD operation

		Or more efficiently, if possible
		if(a > MOD)	a -= MOD;	// given that you are sure we are far by ONLY 1 cycle
		if(a < 0)	a += MOD;



























------------------------------------------------- Operations Tricks --------------------------------------------------------------------
- Floor of 2 positive Integers
	a / b

- Ceil of 2 positive Integers
	(a + b-1) / b

- Round of 2 positive Integers
	(a + b/2) / b

- What about negatives? Similar, but in careful way

- Why care?
	1) Nice tricks
	2) Avoid Double problems
	3) Faster

- How to handle double problems
	1- Awareness of double format is a must. Read Misof article in TC
	2- In case lots of double calculations, do on the fly as much as possible (don't save in variables alot)
	3- What do u expect?

	for (double r=0.0; r!=1.0; r+=0.1)
		printf("*");

	After 10 times r won't be exact equal 1! Double compare should be in different way

	int doubleCompare(double x, double y) {
		if (fabs(x-y) <= EPS)	// Check equality first. EPS is ur define, e.g. 1e-8. BASED on problem requested precision.
			return 0;

		if(x < y)
			return -1;

		return 1;
	}































---------------------------------------------------------Dir Arrays------------------------------------------------------------
Do you remember code that moves in maze?

	bool findEnd(int r, int c)		// Recursion State: r, c
	{
		// Try the 4 neighbor cells
		if(findEnd(r, c-1)) return true;  	// search up
		if(findEnd(r, c+1)) return true; 	// search down
		if(findEnd(r-1, c)) return true;  	// search left
		if(findEnd(r+1, c)) return true;  	// search right

		// Can't find a way for it!
		return false;
	}

What if we do 8 moves? 16 moves? The better is recording how state is changed, and save this in array
int cr[] = {0, 0, -1, 1};
int cc[] = {-1, 1, 0, 0};

In Some problems, you need to order them, e.g. Left, Up, Right, Bottom.
Exercise: How to do it for 8 directions? How array will be for knight move in a chess?

	bool findEnd(int r, int c)		// Recursion State: r, c
	{
		for(int d = 0; d < 4; ++d)
			if(findEnd(r + cr[d], c + cc[d])) return true; 	// change r, c with change in row and change in column

		// Can't find a way for it!
		return false;
	}






















---------------------------------------------------------Memset------------------------------------------------------------
memset: Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char

SO fast: as it directly assign memory blocks.

You could set with it chars in case string, 0 or 1 in case integers and -1 in case doubles.

memset(vis, 0, sizeof(vis));
memset (str,'-',6);

Related Memory methods
memcpy    	Copy block of memory
strncpy 	Copy characters from string
memcmp	    Compare two blocks of memory

------------------------------------------------------------- Memset TLE workaround --------------------------------------------------------

Say you have for every given test case, to mark some numbers in boolean visited array, and check who is marked later.
	Unfortunately array is of Million number and you have many test cases. Code TLE due to memseting each test case. Using set to mark also TLE.

Here is a nice trick. Instead of bool vis[], we will use int vis[], and we will never memset it, default zeros)
	Say we are in t-th test case.
		Mark a visited number with T:		vis[i] = T;
		Check if a cell is visited with 	if(vis[i] == T)

		Intially T = 1, which is default we do. Say in Test Case 1, we marked 2, 5: Then array of 10 is: {0, 0, 1, 0, 0, 1, 0, 0, 0, 0}
		In Test T=2, every number != T is not visited, so whole array is FALSE for us.
		Now mark 5, 7 and 8: {0, 0, 1, 0, 0, 2, 0, 2, 2, 0}	and so on



















------------------------------------------------------ Over Flow ---------------------------------------------------------------
2 cases:
		Output Over Flow: The output itself doesn't fit in basic data types
			Typically, many problems would ask for answer % a number, so results fit.

		Intermediate Over Flow: The trickiest, when intermediate results overflow but output is not.


Checking Overflow
	Say we would like to do a * b, but we want to ignore this operation if it exceeds MAX (e.g. MAX = 32 bit max)


	Convert if(a * b > MAX) continue;
			TO
	Convert if(a > MAX / b) continue;

	What about a * b * c?

	if(a > MAX / b || a * b > MAX / c)	continue;	// Check ab, then abc

	What about a * b + c?

	if(a > MAX / b || a * b > MAX - c)	continue;	// Check ab, then abc

1) Output overflow handling
	In case result is maximum 29 digit, and operations are +, -, * ONLY there is a nice trick.
		Calculate answer long long % 10^18
			Then we have the last 18 digit correctly

		Calculate answer for double
			Then we have the first 13 digit correctly (why?)

		Then use a code to merge them, e.g.

		public static String MergeResults30DigitsMax(double doubleResult, long longResult)
		{
			String doubleStr = String.format("%.0f", doubleResult); //format to avoid 0's

			if (doubleStr.length() <= 18)
				return String.valueOf(longResult);	// then long maintain value by itself

			doubleStr = doubleStr.substring(0, doubleStr.length() - 18);

			// Cut last 18 digit of double and replace them with long
			return doubleStr + String.format("%018d", longResult);	// format long due to trailing zeros
		}

	If result is up to 30 digit, code will probably work, except case when boundaries of numbers are 0000 or 99999 (e.g. can't handle 10^30)

	For digits more than 30, using Big Integer is a must

	-----------------

2) Intermediate Over Flow, but output fit
	a) Sometimes, the intermediate overflow is your code fault
		E.g. Your fraction class sum 2 fractions by multiplying their denominator while should utilize LCM of them

			1/12 + 1/8 = (8 + 12) / (12 * 8)

			Correct	   =   / LCM(8, 12)

	b) Sometimes, it is mandatory. Here is a trick if operations are +, -, * ONLY

		Assume that F(...) has maximum output X, select an integer Y > X
		and calc F()%Y which will be result


	 	What if X e.g. fits in 32 bit, then Y will be more than 32 bit and most probably overflow occurs!

	 	Here is a better trick

		Find set of small prime numbers p1, p2, p3 .. such that their multiplication > X
			E.g. 257, 263, 269, 271 -> 4 primes their multiplication > 2^32

		Find F() % pi

		Now we have 4 primes, and 4 Mode results...How to combine them to get F() % (p1 * p2 ....)?
		 	 Chinese remainder theorem

















---------------------------------------------------------Compressing Array of Numbers------------------------------------------------------------
Say we have vector numbers, each of value max 9, and we need to use them as state: build a vector of compressed number.

	Idea is to compress them in set of long longs, as long long can have more numbers, add it.
	1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5 7 6 1 8 9 2 7 9 5 4 3 1 2 3 3 4 1 1 3 8 7 4 2 7 7 9 3 1 9 8
	1740948824551711527 6142322168576189279 5431233411387427793 198
		-> So 60 numbers compressed to 4 numbers.
		-> Imagine how this could be fast in some situations?

	How to do so? if we have 1 7 4 -> 1*10+7 = 17 * 10 + 4 = 174, but before doing this operation make sure no over flow

	vector<ll> compress(vector<int> v)
	{
		vector<ll> ret;
		ret.push_back(0);

		rep(i, v) {
			if(ret.back() > LONG_LONG_MAX / 10 || ret.back()*10 > LONG_LONG_MAX - v[i])
				ret.push_back(0);

			ret.back() = ret.back() * 10 + v[i];
		}

		return ret;
	}

	What if numbers are max of 123? Then instead of 10 use 124. In other words, we compress them base 124
*/























