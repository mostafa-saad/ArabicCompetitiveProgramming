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
Introducion
Basic Examples
How to trace recursion
Merge Sort
Max Sum Path in grid from (0, 0) to (n, n)
Find Path in Maze
Handling Cycles
Flood Fill
Connected Components
Generating binary/ternary Sequences
Permutations / Combinations
Stack Overflow notes
Iterative Recursion: stack usage
Search space analysis / # Recursion Calls
Introduction to Dynamic Programming
*/

const int MAX = 100;
int n;
bool valid(int i, int j) { 	return 1;	}


















// a function is said to be recursive if it calls itself.

void SayIamTopCoder(int cnt)
{
    if(cnt < 1)						// Base Case
		return;

    cout<<"I am  TopCoder.\n";		// Some logic

    SayIamTopCoder(cnt - 1);		// Sub-problem - never go to infinity
}












// Trace a4(4)

int a1(int n)
{
	return n;
}

int a2(int n)
{
	return n * a1(n-1);
}

int a3(int n)
{
	return n * a2(n-1);
}

int a4(int n)
{
	return n * a3(n-1);
}



// If you are in function F1, and need to call function F2 that behaves exact as F1, then just call F1



// Factorial(n) = n * Factorial(n-1).		Factorial(0) = Factorial(1) = 1
int Fact(int n)
{
	if(n <= 1)
		return 1;

	return n * Fact(n-1);
}

/*

Fact(4)
	4* Fact(3)
		3* Fact(2)
			2* Fact(1)
			2* 1 <-- 2
		3* 2 <-- 6
	4* 6 <-- 24
*/


// Check Stack Trace Image













void Triangle(int x) {
   if (x <= 0) return;

   Triangle(x - 1);

   for (int i = 1; i <= x; i++)
        cout << "*";
   cout << endl;
}


/*
Call Triangle(7)
Triangle(7)
  Triangle(6)
    Triangle(5)
      Triangle(4)
        Triangle(3)
          Triangle(2)
            Triangle(1)
              Triangle(0) <-- base case
            Triangle(1) <-- prints 1 star & new line
          Triangle(2) <-- prints 2 stars & new line
        Triangle(3) <-- prints 3 stars & new line
      Triangle(4) <-- prints 4 stars & new line
    Triangle(5) <-- prints 5 stars & new line
  Triangle(6) <-- prints 6 stars & new line
Triangle(7) <-- prints 7 stars & new line

The output will be:

*
**
***
****
*****
******
*******
*/


void TriangleRev(int x) {
   if (x <= 0) return;

   for (int i = 1; i <= x; i++)
        cout << "*";

	cout << endl;

	TriangleRev(x - 1);
}

/*
Call TriangleRev(7)
TriangleRev(7) <-- prints 7 stars & new line
  TriangleRev(6) <-- prints 6 stars & new line
    TriangleRev(5) <-- prints 5 stars & new line
      TriangleRev(4) <-- prints 4 stars & new line
        TriangleRev(3) <-- prints 3 stars & new line
          TriangleRev(2) <-- prints 2 stars & new line
            TriangleRev(1) <-- prints 1 star & new line
              TriangleRev(0) <-- base case
            TriangleRev(1)
          TriangleRev(2)
        TriangleRev(3)
      TriangleRev(4)
    TriangleRev(5)
  TriangleRev(6)
TriangleRev(7)

The output will be:
*******
******
*****
****
***
**
*


*/












// 3n+1 Series:  Next(n):	if n is odd then n = 3 *n +1. 	If n is even then n = n/2.		if n == 1, stop
// E.g. 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
// Given n, find length of 3n+1 sequence. E.g. F3n_1(22) = 16

int F3n_1(int n)		// Recursion State: n
{
	if(n == 1)
		return 1;

	if(n%2 == 0)
		return 1 + F3n_1(n/2);	// 1+ as we have an element in the sequence

	return 1 + F3n_1(3 *n + 1);
}

// How to trace recursion













void mergesort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int mid =(low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        // linearly, merge to sorted blocks
    }
}








void printNumber(int n)	// for n > 0
{	// 1234567
	if(n)
	{
		printNumber(n/10);		// 214/10 = 21
		cout<<n%10;				// 214%10 = 4
	}
}




// E.g. 7 = 111		214 = 11010110
// If number%2 get for us last bit in binray representation
// If we could print last bit, we could print
void printNumberBits(int n)	// for n > 0
{
	if(n)
	{
		printNumberBits(n/2);	// 214/2 = 1101011		last bit removed
		cout<<n%2;				// 214%2 = 0
	}
}
























// Given grid of positive numbers, Start from 0, 0 and end at n, n. Move only to right and down - find path with sum of numbers is maximum.
/*
15
24

512
678
189
*/
int grid[MAX][MAX];

// Think in function F(i, j) that find solution from (i, j) to (n, n)

int maxPathSum(int r, int c)
{
	if( !valid(r, c))
		return 0;

	if (r == n-1 && c == n-1)
		return grid[r][c];	// base

	int path1 = maxPathSum(r, c+1);	// right
	int path2 = maxPathSum(r+1, c);	// down

	return grid[r][c] + max(path1, path2);
}









/*

.SX..
..X.E
....X
X.XX.
 */

char maze[MAX][MAX];	// filled with S (for start), E (for end), . (could pass) and X (block can't path)
bool findEnd(int r, int c)		// Recursion State: r, c
{
    if( !valid(r, c) || maze[r][c] == 'X')
		return false;		// invalid position or block position


    if( maze[r][c] =='E')
		return true;	// we found End

	// Try the 4 neighbor cells

	if(findEnd(r, c-1)) return true;  	// search up
    if(findEnd(r, c+1)) return true; 	// search down
    if(findEnd(r-1, c)) return true;  	// search left
    if(findEnd(r+1, c)) return true;  	// search right

	// Can't find a way for it!
    return false;
}




// This code will go to infinity! ... we need to avoid cycles. Mark visited cells

bool vis[MAX][MAX];
bool findEnd2(int r, int c)	// Recursion State: r, c	and FULL visted array
{
    if( !valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
		return false;		// invalid position or block position


	vis[r][c] = 1;	// we just visited it, don't allow any one bacl to it

    if( maze[r][c] =='E')
		return true;	// we found End

	// Try the 4 neighbor cells

	if(findEnd2(r, c-1)) return true;  	// search up
    if(findEnd2(r, c+1)) return true; 	// search down
    if(findEnd2(r-1, c)) return true;  	// search left
    if(findEnd2(r+1, c)) return true;  	// search right

	vis[r][c] = 0;	// undo marking, other paths allowed to use it now

	// Can't find a way for it!
    return false;
}

/*

// Typical backtracking procedure
void recursion(state s)
{
	if( base(s) )
		return ;

	for each substate ss
		mark ss

		recursion (ss)

		unmark ss
}

 */











// Flood Fill...given maze where cells are . or X. You start at 0, 0..how many cells you could reach?
/*
..X.
.X.X
..X.

...x.
..x..
.x...
x....


....X...
....XXXX
..X.....
.X....XX
..X.X.X.
..X...X.
...X..XX
*/

// A reachable block is called connected components. Each set of positions reachable together are connected component.


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
void cntComponents(int R, int C)
{
	int comps = 0;

	for(int i = 0; i < R; ++i)
	{
		for(int j = 0; j < C; ++j)
		{
			cnt = 0;
			cntReachalbleCells(i, j);

			if(cnt > 0)
				comps++;
		}
	}

}



















// generate all sequences of given length, of zeros and ones
// E.g. for len = 3:	000, 001, 010, 011, 100, 101, 110, 111
//								""												Count=1
//					0								1							Count=2
//			00 				01				10				11					Count=4
//		000		001		010		011		100		101		110		11				Count=8
//
void generateBinary(int len, string cur = "")	// recursion state: integer, string
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
void generateTernary(int len, string cur = "")
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


















// Print all possible permutations of numbers 0, 1, 2, ...n-1
void perm(int i, int n, int vis[], int cur[])
{
	if(i == n)
	{
		for (int j = 0; j < n; ++j)
			cout<<cur[j];
		cout<<"\n";
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


















// print N choose M combinations
void comb(int i, int n, int m, int cur[], int curLen)
{
	if(curLen == m)
	{
		for (int j = 0; j < m; ++j)
			cout<<cur[j];
		cout<<"\n";
		return;
	}

	if(i == n)	// we reached end, and have current combination is not correct
		return;

	// take it
	cur[curLen] = i;
	comb(i+1, n, m, cur, curLen+1);

	// don't take it
	comb(i+1, n, m, cur, curLen);
}

























// Could we do recursion calls as we want? NO, you have stack limit size.
// Say your function call reserve 1 integer (4 bytes) and a call need 2 pointers (8 bytes) for saving some return addresses
// Say you have 1.5MB stack size, then you could do maximum 1.5MB / 12 bytes ~= 144617 call
int dep = 0;

void stackTest1()
{
	cout<<dep++<<"\n"<<flush;
	stackTest1();
}

void stackTest2(int a = 1)
{
	cout<<dep++<<"\n"<<flush;
	stackTest2(a);
}

void stackTest3()
{
	cout<<dep++<<"\n"<<flush;
	int arr[50];	// be careful from your created items. E.g. Integrs, Strings, Structs.
	stackTest3();
}

void stackTest4()
{
	cout<<dep++<<"\n"<<flush;
	int arr[100];	// be careful from your created items. E.g. Integrs, Strings, Structs.
	stackTest4();
}

void stackTest5()
{
	cout<<dep++<<"\n"<<flush;
	int arr[50];
	vector<int> v(50);	// Its internal array on heap not on stack
	stackTest5();
}

void stackTest6()
{
	cout<<dep++<<"\n"<<flush;
	int arr[50];
	vector<int> v(1000);	// Its internal array on heap not on stack. Then watch from heap too
	stackTest6();
}

void stackTest7()
{
	cout<<dep++<<"\n"<<flush;
	int arr[1000];
	stackTest7();
}

void stackTest8()
{
	cout<<dep++<<"\n"<<flush;
	int arr[1000000];	// So big for my MACHINE stack limit
	stackTest8();
}

void stackTest9(int a[])	// this is array reference. it behaves as if it is just an integer
{
	cout<<dep++<<"\n"<<flush;

	stackTest9(a);
}



int arr[1000000];




int main()
{


	stackTest9(arr);

	return 0;
}




















// How to avoid stack problems
// 1- If must do it in recursion, then avoid any unnecessary local data. Move to global as possible
// 2- Move to iterative procedure
// 3- Implement your own stack calls!

void generateTernary_myStack(int len)
{
	stack< pair<int, string> > st;	// create stack consist of recursion state
	st.push( make_pair(len, "") );

	while(!st.empty())
	{
		int len = st.top().first;
		string cur = st.top().second;
		st.pop();

		if(len == 0) {
			cout<<cur<<"\n";
			continue;
		}

		st.push(make_pair(len-1, cur + "0"));
		st.push(make_pair(len-1, cur + "1"));
		st.push(make_pair(len-1, cur + "2"));

	}
}





// Search space analysis

// int F(int a)
//		1 <= a <= n									Search space size : n

// int F(int a, int b)
//		1 <= a, b <= n								Search space size : n^2

// int F(int a, int b, int vis[]):
//		1 <= a, b <= n
//		vis is boolean
//		visLen <= m									Search space size : n^2 * 2^m

// int F(string cur)
//		cur string of chars A, B, C, D
//		curLen <= n									Search space size : 4^n

// int F(string cur)
//		cur string of chars A, B, C, D
//		curLen <= n
//		One of characters them repeats curLen-1 times (e.g. AAAB, AABA, ABAA, BAAA, AAAC, AACA...)
//													Search space size : 10 * n	- CONSIDER space limitations





// Fibonacci Series: Fib(n) = fib(n-1) + fib(n-2).	Fib(0) = fib(1) = 1
int fib(int n)
{
	if(n <= 1)
		return 1;

	return fib(n-2) + fib(n-1);
}

// what is search space? n
// what is number of recursive calls? We are branching every time to 2 levels that differs in 1
//										fib(5)
//							fib(4)											fib(3)
//				fib(3)					fib(2)						fib(2)			fib(1)
//		fib(2)			fib(1)	fib(1)			fib(0)		fib(1)			fib(0)
//	fib(1)	fib(1)
//
// We almost have 2^N calls

// Wait, a space of N, is called 2^N times!
// A fib of 50 do around ~1125899906842624 call!!!!!!
//
// Then, we must call a state more than once? and it too call other states, that already called!
//
// Check tree above, fib(3) called twice. Fib(2) called three times!
//
// Let's SAVE the answer, and let space of N is called 2N times!


int savedAnswers[MAX];		/// Initialized to -1, means no answer
int fibSave(int n)
{
	if(n <= 1)
		return 1;

	if(savedAnswers[n] != -1)
		return savedAnswers[n];

	return savedAnswers[n] = fib(n-2) + fib(n-1);
}

//													fib(5)=8
//									fib(4)=5							fib(3)=3
//						fib(3)=3					fib(2)=2
//			fib(2)=2				fib(1)=1
//	fib(1)=1		fib(1)=1
