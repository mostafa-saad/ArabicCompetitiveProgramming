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
At Most vs Exact relationship
Variables Inference
Canonical Form
Sliding Window
Pigeonhole principle
Online PreComputations
Offline PreComputations
Locality of reference

Problems: UVA(454, 507, 108, 11237). TC(SRM391-1-1, SRM310-1-2, SRM521-1-2, TCO13-QRB-3

Links
http://en.wikipedia.org/wiki/Summed_area_table
http://zimmer.csufresno.edu/~larryc/proofs/proofs.pigeonhole.html
http://en.wikipedia.org/wiki/Pigeonhole_principle
http://en.wikipedia.org/wiki/Canonical_form

 */






/*














-------------------------------------------- At Most vs Exact relationship --------------------------------------------

	Say we have N balls, and would like to 
		know in how many ways, we could got EXACTLY M balls?	OR
		know in how many ways, we could got AT MOST M balls?	OR
		
	The interesting her is there relations.
		Say we have wrote a function that calc EXACT(N, M).
			Then we could calculate AT_MOST(N, M) = EXACT(N, 0) + EXACT(N, 1) + .... EXACT(N, M)
			
		What if we found it easily/efficient to write Function AT_MOST(N, M)
			Then we could calculate EXACT(N, M) = AT_MOST(N, M) - AT_MOST(N, M-1) 
		
	
	Whenever in a problem, the definition of atmost/extact is available, then if problem asked to calculate in one of them, you could think in the other.
	
	In DP, sometimes, Order of AT_MOST is much better than Exact.





















-------------------------------------------- Variables Inference--------------------------------------------
Variable inference is to infer values of variables from others. This many times reduce algorithm order

	E.g.	Count number of (a, b, c, d) where 0 <= a, b, c, d <= 100 && a+b+c+d = 150

		A typical solution	O(N^4)

			for over a
				for over b
					for over c
						for over d
							if(a+b+c+d == 150)
								Count++


		Could we infer any variable, so that we remove one of loops? YES.
			a+b+c+d = 150 -> d = 150 - (a+b+c)

			Then new solution	-> O(n^3)

				for over a
					for over b
						for over c
							d = 150 - (a+b+c)
							if(d >= 0 && d <= 100)
								count++



	E.g.g Given a, b, c. We would like them to be a' * b' = c'. You are allowed to change a, b, c such that multiplication is valid.
		Return min change, that is: |a-a'| + |b-b'| + |c-c'| minimum

		We need to try all possible values for a, b, c, like above.  But in fact, easy to drop c loop. If we have a' and b' we know c' = a'*b'c.
			This makes O(n^2) solution. Could we infer one more variable!

		say we have a = 4, b = 2, c = 20

			say we try a' = 5, do we need to try b's? NO, we need answer so close to c.
				Then b' = c/a' = 20/5 = 4.

				What if c = 21.
					b' = 21/5 = 4. fraction.	Then try b' once as FLOOR, and once as CEIL

		This is an O(n) solution!




























-------------------------------------------- Canonical Form --------------------------------------------
Sometimes, we have many objects (arrays, strings, polygons, trees, ..), and each one of them has may formats.
	Solution depends on knowing what are similar ones, but each one has many states.
	Key is to define a Canonical Form, such that any given object has ONLY one status.
	This way when we have different objects, we could know exactly who are similar.


	E.g. Given set of strings, we could do operations on any them. Operation is swap of 2 chars.
		 What are the maximum number of strings that could be transformed to each other?

		 It is well known that using swap operations, we could SORT any string.
		 Then, for any string X, its canonical form is SORT(X)
		 Now, find canonical of all strings.
		 For each string, find how many times it is repeated in the list. Maximum is the answer.


	E.g. Say we have triangles, then a Canonical form of a triangle is its sides sorted.
		So triangle of sides (5, 2, 6) -> Canonical : (2, 5, 7)



	E.g. Given 2 trees, how to find a Canonical form for it?

	Sometimes, it is much harder and you need to think how to find one FORM for a given object (e.g. a polygon / graph)


	*SUM UP: whenever needs equality between things that has many formats, think about Canonical Form.
































-------------------------------------------- Sliding Window --------------------------------------------

	Given an array and k, find sub-array of length K with maximum Sum
	
	Think in the array: [a b c d e f g h] with k = 3
	Then we want to check:
	[a b c]
	  [b c d]
		[c d e]
		  [d e f]
			[e f g]
			  [f g h]


	
	Each one of them is called a window, and moving from window to another called Sliding Window. This is called FIXED size Sliding Window.
	



	How to implement:

		int max = 0;
		for(int i = 0; i < n-k+1; i++)		O(n^2)
		{
			int sum = 0;
			for(int win = 0 ; win < k; win++)
				sum += A[i+win];

			if(i == 0 || sum > max)
				max = sum;
		}








	Could we do better? Check the windows again. What is relation between consecutive windows? One number is removed and one number is entered.
	int max = 0;
		for(int win = 0 ; win < k; win++)
			max += A[win];

	sum = max;
	for(int i = 1; i < n-k+1; i++)	O(n)
	{
		sum = sum - A[i-1] + A[i+k];	remove first of last window, and add new one
	}






	*SUM UP: Whenever the request is a consecutive range of input, think sliding window wise, in other words, start from first window and find target window.















	Given array and k, find longest range such that max-min <= k.
		This is a VARIABLE size sliding window. Either convert it to FIXED or find an algorithm to get the VARIABLE window.

		To convert for fixed, try every length, and then run a fixed sizing window

		For Each length
			Do similar to above algorithm. Note, we can't maintain relation between consecutive windows, so we will do it in O(n^2)

		Total Order O(n^3). We could improve it to N^2logN, but let's try a variable size way.

		*) Start with an empty window, as long as u can add new elements, add them,
		*) Else start to remove the elements from the start. Use multiset.

		E.g. A[] = {2, 3, 2, 1, 4, 10, 9, 8, 7, 2}	K = 7

		Start with 								{}
			2? YES								{2}
			3? YES								{2, 3}
			2? YES								{2, 2, 3}
			1? YES								{1, 2, 2, 3}
			4? YES								{1, 2, 2, 3, 4}
			10? NO 10-1 > 7.   Remove 2			{1, 2, 3, 4, 10}	Still NO
						   	   Remove 3			{1, 2, 4, 10}		Still NO
						   	   Remove 2			{1, 4, 10}			Still NO
						   	   Remove 1			{4, 10}				YES, 10-4 <= 7
			9? Yes								{4, 9, 10}
			8? Yes								{4, 8, 9, 10}
			7? Yes								{4, 7, 8, 9, 10}
			2? NO	10-2 > 7   Remove 4			{2, 7, 8, 9, 10}
			2? NO			   Remove 10		{2, 7, 8, 9}		YES...and so on


			For each YES, maximize over the multiset length.















	Given an array, find sub-array with maximum Sum. Notice, this time window is variable size.
		Again, you could try every length, and O(n) find max sum, and maximize over maximums.

		Let's try a variable sliding window size. Here is one general way that to may work with variable windows.

		Say we are given A = [a, b, c, d, ... ]
			Start with first element in array. This is the first window. {a}
		 	Move to next element, could we extend the window do {a, b} or we must remove a?
		 		Say we managed to add it.
		 	Move to c. Could we extend window with it to {a, b, c}? or must remove a? or must remove a and b?

		 	and so on. So each time window ends at current element. Let's apply it.


		 Given an array, let's find maximum sum.
		 Say we started with first element. And now we moved to 2nd element.
		 	 We have 2 statuses for window so far: positive or negative.
		 	 Same new element has 2 statues: : positive or negative.

		 	 If we have a negative window, this we always need to skip it and use the new value.
		 	 	 E.g. WindowSumSoFar  = -10.	New element = 5. 	5 	> -10+5
		 	 	 E.g. WindowSumSoFar  = -10.	New element = -3. 	-3 	> -10-3

		 	 If we have a positive window, it always better to add the new element for it
		 	 E.g. WindowSumSoFar  = 10.	New element = 5. 	10+5 	> 5
		 	 E.g. WindowSumSoFar  = 10.	New element = -3. 	10-3 	> -3
		 	 E.g. WindowSumSoFar  = 10.	New element = -40 	10-40 	> -40

		 		MaximumOfWindows = WindowSumSoFar = 0;

				for(int i = 0; i < n; i++)
				{
					if(WindowSumSoFar < 0)
						WindowSumSoFar = A[i];
					else
						WindowSumSoFar += A[i];

					MaximumOfWindows = max(MaximumOfWindows, WindowSumSoFar);
				}


	There are many problems there for window, some of them needs advanced data structures like Segment tree and BIT.


































-------------------------------------------- Pigeonhole principle--------------------------------------------

The pigeonhole principle states that if n items are put into m pigeonholes with n > m, then at least one pigeonhole must contain more than one item

	Theorem: Among any N positive integers, there exists 2 whose difference is divisible by N-1.
		Then we have N-1 pigeonhole, and want to set N items in them. At least one pigeonhole must contain more than one item.

		In other words, for each number calc: A[i]%N-1. Then we have N integers, their modes are [0 - N-1]. So at least 1 duplicate.
		Get the 2 numbers with same mode, they are the answer.

		E.g. N = 5. A = [2, 3, 5, 7, 8]. Modes = {2, 3, 1, 3, 0}. 5 numbers, with values [0-3]. Pick 2 with same mode.
		 Then, (3, 7) are the answer

	Theorem: For any N positive integers, the sum of SOME of these integers is divisible by M, where M <= N.
		let's pick worst case, M = N

		This a bit tricky. If we found one of numbers with value zero, we are done. If we couldn't find:

		Let's calculate the accumulative array AC: (a1, a1+a2, a1+a2+a3....)

		Take mode for accumulative array, this means we have N integers with modes [1 - N-1]
		Say AC[3] % N = AC[6] = % N
			Then (AC[6] - AC[3]) % N = 0
		  	  Then Range (a4+a5+a6) % N = 0


Other interesting principles: Triangle inequality


































-------------------------------------------- Online vs Offline PreComputations--------------------------------------------

Sometimes, the program calculations are too much, and we need to make it faster...2 approaches for that.

- Online PreComputations
	By Online PreComputations, we mean to do little calculations and savings before starting the main processing. Occurs highly in query problems.
	
	E.g. Given an array, and set of queries: position, what is sum of values in range [1, position]
		E.g. 5 2 3 4 10
			Q1: 3 -> 10
			Q2: 5 -> 24
			
		If we have Q queries and a array of length N, then we do O(NQ)
		
		How to do PreProcessing? Simply let each item be sum of all numbers since it
			Then 	5 2 3 4 10
					5 7 10 14 24	(each index is such of values form 0 to index)
					
					Code:
					int A[] = {5, 2, 3, 4, 10}
					int B[];
					B[0] = A[0];
					for(int i = 1; i < len ++i)
						B[i] += B[i-1] + A[i];					this is called accumulated array, you could use STL to do it for you
						
			Now for any quersy answer is B[position-1]
			Then new order is O(N+Q) N time preprocessing and Q for queries
			
			





















	E.g. Given an array, and set of queries: start and end indices, what is sum of values in range [start, end]
		E.g. 5 2 3 4 10
			Q1: 1-3 -> 10
			Q2: 2-5 -> 19
			
		Let's make use of accumulated array. Assume start & end are zero based.
			B[end] 		= A[end] + A[end-1] ... A[start]+A[start-1]....A[0]
			B[start] 	= 						A[start]+A[start-1]....A[0]
			
			Then B[end] - B[start-1] = A[end] + A[end-1] ... A[start]
			
			Then also we could answer such queries in O(N+Q)





		Problem: Given set of queries start, end : count number of primes in this range
			1- Check is prime in the whole range once, and set answers in bool array
			2- Build accumulated array and answer the queries












	
	E.g. Given a 2d Array, and set of queries in rectangle format: (i, j) and (k, l) -> What is sum in the given rectangle?
	
		This problem arised in Image Processing field, known as Image Integral. Like above one, is solved by accumulated 2d array (DP).

		First, do accumulation per each row like above. Then, each row index, is sum from 0 to index.
		Now, on the row accumulated matrix, do accumulation on the columns, from top to down.
			What accumulated[k][l] means? It is sum of rectangle (0, 0) - (k, l)
			
			What about rectangle {(i, j) and (k, l)}: accumulated[k][l] - accumulated[k][j-1] - accumulated[i-1][l] + accumulated[i-1][j-1];
				Draw it.
				
			accumulated[k][l] is whole array from (0, 0) - (k, l)
				But we added 2 unreleated other sub-rectanges, (0, 0) - (k, j-1) and (0, 0) - (i-1, l)
				Fine let's Substract them
				
				Wait! They both are shared in (0, 0) - (i-1, j-1), we subtracted it twice! Fine, readd it.
				
		As Example, Say we have 2d Array
			1  2  3  4
			5  1  2  4
			1  1  2  1
			3  2  1  1
			
			After row accumulation
			
			1  3  6  10
			5  6  8  12
			1  2  4  5
			3  5  6  7
			
			After column accumulation
			
			1  3  6  10
			6  9  14 22
			7  11 18 27
			10 16 24 34
			
			Value in (1, 1) = 9 = (0, 0) - (1, l) = 1 + 2 + 5 + 1

			Value (2, 2) - (3, 3) = 24 - 14 - 10 + 6 = 2 + 1 + 1 + 1




















	E.g. Given an array, and set of queries: start and end indices: What is minimum of of the interval.
		A typical code will need to iterate over range [start, end] -> So order O(QN)

		let's do some pre-processing. Let's divide array to blocks, each of size SQRT(N)
			In O(N), calculate the minimum in this block.

			Now given a query. Then it must start in mid of a block, passing by some blocks, ending at mid of some block.
				Minimum is: min elements in a before partial block, one min for each block, min elements in a after partial block

			E.g. say we have an array of 16 element: 1 2 1 3 	4 5 9 7  	 3 3 3 3	4 8 12 2
			Now sqrt(n) = 4. Divide array to blocks of 4. Calculate min of each block
														1			4			3			2

			Assume we have query(4, 11): this is 2 full blocks. Answer is min(2nd block, 3rd block) = min(4, 3) = 3.

			Assume query (2, 14): Then we have 2 numbers inside 1st block {1, 3} and 2 blocks: 2nd, 3rd, and 3 numbers from last block: {4, 8, 12}
				So answer is min(1, 3, 4, 3, 4, 8, 12) = 1

			Order O(n Sqrt(n) )































- Offline Per-computations

	- This is the solution for who can't think in a solution and time is running out.

	- idea is simple. Write a code that generates some data, and HARD CODE this data in the program to help you somehow.
	
	- E.g. Say we are asked to Count primes in range 10^8
		- If we tried Sieve it will suffer from both time and memory (10^8 array)

		- Machine is yours, but judge machine is not.

		- Write Sieve and print on file the answer of each 1-Million Answer. They will be 100 Number
			- First number, is # of primes in range  [1 - 1 Million]
			- Second number, is # of primes in range [1 - 2 Million] and so on.
			- Take numbers from file/console and set them in an primesCount[100]

		- Now re-wrirte your code such that, when you are asked to count in range [1-M]
			- See where is M in array. Say M is 2.5 Million. Then all what we need to do is counting primes in range 2000001 to 2500000
			- That is for each judge request, you do only 1 Million operation instead of 100 Million.
			- It is easy to write variation of seive that count primes in certain range.
			- Then asnwer is primesCount[input/1000000 -1] + Seive((input/1000000) *1000000+1, input)





























-------------------------------------------- Locality of reference --------------------------------------------

How is accessing a variable is fast? Depends on where it is.
	CPU registers (8-128 registers) 					– immediate access
	L1 CPU caches (32 KB to 512 KB) 					– fast access
	L2 CPU caches (128 KB to 24 MB) 					– slightly slower access
	Main physical memory (RAM) (256 MB to 64 GB)		– slow access
	Disk (file system) (100 GB to 10 TB) 				– very slow








* Following is an informal idea simplified for explanation, not necessarily completely true.



	Say we have an Array. When we start to access an index, a block around this index is copied from memory to one of caches.
	Let's imagine that

		Say we have a 1 million array of integers. Then it needs 4 Milion Byte. 4 Milion / 1024 KB = 3906.25 KB = 3 MB
		Say Cache 32 KB and processor will move for an accessed index index to index+20 KB -> [0 - 20*1024/4] = 5120 consecutive integer.

		Then when we access A[0], a 5120 consecutive integer will be loaded.
			Then when we access integers from A[1] to A[5119], they are in Cache, so they are retrieved so FAST.
			Then, when we access consecutive elements, this is so fast. Aka, a row major order iterating

		Note: a 2d R*C array, is represented as R*C 1D array.

		Now let's imaging we have 2D array[100][5120]. Say we access it in column order:
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; j++)
					A[j][i]


			So first access A[0][0], loads First row in the array. Do A[1][0] exist in Cache? NO load it. Is A[2][0] in Cache? NO....

			Column major order iterating is sooo slow.


















	Test following code:

	const int MAX = 1000;
	int A[MAX][MAX];

	int main()
	{
		for(int k = 0; k < MAX; ++k)
			for(int i = 0; i < MAX; i++)
				for(int j = 0 ; j < MAX; j++)
					A[i][j] = i*j;
		return 0;
	}

	Change it to: A[j][i] = i*j;	and see Time Difference.

















Two types of locality:

	Spatial locality: if a particular memory location is referenced at a particular time, then it is likely that nearby memory locations will
		be referenced in the near future.

	Temporal locality: if at one point in time a particular memory location is referenced, then it is likely that the same location will be
		referenced again in the near future.



























let's see how considering them affect highly matrix multiplication
	
	
for i in 0..n
  for j in 0..m
    for k in 0..p
      C[i][j] = C[i][j] + A[i][k] * B[k][j];


Study each matrix is accessed..who is row major and who is column major?
	C[i][j] is row major
	A[i][k] is row major
	B[k][j] is colum major

Mathematically, it doesn't matter if loops J, K are swapped. Now ALL of them are row major, which is faster.

Think Row Wise -> Better Spatial Locality
	for i in 0..n
	  for k in 0..p
		for j in 0..m
		  C[i][j] = C[i][j] + A[i][k] * B[k][j];	 


Although we access them in row major order now, each index is accesses many times, and it won't be in memory.
	  
Think Block Wise -> Temporal locality 

	for (ii = 0; ii < SIZE; ii += BLOCK_SIZE)
	  for (kk = 0; kk < SIZE; kk += BLOCK_SIZE)
		for (jj = 0; jj < SIZE; jj += BLOCK_SIZE)
		  for (i = ii; i < ii + BLOCK_SIZE && i < SIZE; i++)
			for (k = kk; k < kk + BLOCK_SIZE && k < SIZE; k++)
			  for (j = jj; j < jj + BLOCK_SIZE && j < SIZE; j++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			
			
































Do you remember Sieve, and how we use it filter non primes and then count primes.

int countPrimesInRange_sieve1(int n)	Imagine N = 10^8
{
	vector<bool> isPrime(n+1, true);
	isPrime[0] = isPrime[1] = 0;

    for (ll i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)
            	isPrime[j] = 0;	Fine spatial Locality, so bad in Temporal locality
								Every prime, iterate over whole array(isPrime), enters it sequentillay in cashe, and it go out. Repeat and repeat!!!
								When isPrime is so BLOCK_SIZE, this is not practical at all!
        }
    }

    int cnt = 0;

    for (int i = 0; i < (int)isPrime.size(); ++i)
    	if(isPrime[i])
    		cnt++;

    return cnt;
}





-> it iterates sequentially, so it has good Spatial locality.
-> But, it has so bad temporal locality. Each prime pass on whole array. So we access same location many times, and it won't be in cache.

-> How to provide better Temporal locality? Simply Let each block of isPrime be processed once.
-> Instead of using primes list and filter our in whole list
-> Filter them block by block







int countPrimesInRange_sieve2(int n)
{
	1) Say N is 10^8, then sqrt(n) is enough to filter all primes
	2) Let BLOCK_SIZE = 10000+1. 
	
	vector<bool> isPrime(BLOCK_SIZE, true);
	
	3) Generate the primes in range BLOCK_SIZE
	
	4) for(int START = 0; START < n; START += BLOCK_SIZE)
		Iterate over prime numbers list
			For each prime, filter numbers in range [START, START+BLOCK_SIZE] smartly using isPrime array (you will need to maintain another offset array).
			
		Iterate over isPrime and count prime numbers
	}
	return count;
}



Note, for primes list array, again it has good spatial but bad temporal. But notice, it is a small array, so won't has that bad effect of isPrime.

Run old code on n = 10^8 and new code, and see the speed difference!
Do you see how this code saved O(n) memory!
This code is O(sqrt(n)) memory
Say we use a char byte to represent 16 odd number (we don't need to consider evens),
Could you imagine how this algorithm is fast in time & memory?






Finally, Why quicksort is always faster than other nlogn algorithms?
	Due to its Spatial locality of reference
	E.g. the next accessed element most of time near to the last accessed index

	
	







*/
