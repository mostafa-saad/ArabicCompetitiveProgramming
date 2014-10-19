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
 ContentLink:
 
 Content:
 Maze Example
 Backtracking vs BruteForce
 Backtracking vs FloodFill
 Eight Queens Puzzle
 Speeding tricks
 - Randomize sub-states
 - Smart Data Structure
 - Solution properties (e.g. symmetry)
 - Prunning
 - Prunning with Data Sorting
 - Sub-states order based on expected depth
 
 Problems: UVA(750, 441, 10344, 529, 732, 10496, 838, 10276, 167, 11195), Usaco Checker Challenge (checker)
 Others: http://apps.topcoder.com/forums/;jsessionid=1AB87B20745A444893D11AFE791A26C9?module=Thread&threadID=627691&start=0&mc=8#1040369
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

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const ll OO = 1e8;

const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

const int MAX_GRID = 100;
int n;
bool valid(int i, int j) { 	return 1;	}




















/*
 *
 * Prerequisite sessions:
 * A must		-> Algorithms - Misc - 01 - Recursion
 * Preferred	-> Algorithms - Graph Theory - 02 - DFS
 *
 */



/*
 * Say we have maze with Start(S), End(E), Blocks(#) and Allowed(.)
 *
 * We need to know how many paths from S to E.
 *
 * S..
 * .#.
 * #..
 * ...
 * .E.
 *
 * One important note, from any location you have up to 4 possible moves! BackTracking involves many DECISIONS per state.
 *
 * let's represent a path with notations L, R, U, D for the 4 directions (Left, Right, Up, Down)
 *
 * Exploring the maze, we could go from S to E using any of following paths:
 *
 * RRDDDDL
 * RRDDDLD
 * RRDDDLLDR
 * RRDDLDD
 * RRDDLDRDL
 * RRDDLDLDR
 *
 * If your algorithm explored all possible paths to reach GOAL in an INDEPENDENT manner, this is brute force approaching.
 *
 * If the exploration utilized the progress of a path, this is Backtracking (e.g. notice how all paths share RRDD). Imagine exploration as a tree.
 *
 * 														R
 *	 													R
 * 														D
 * 														D
 * 					D																		L					-> 2 choices for this state D or L
 * 			D				L																D
 * 		L				D		L													D		R		L
 * 		*				*		D													*		D		D
 * 								R															L		R
 * 								*															*		*			-> * are leaf nodes, where no more going
 *
 * If we wrote code to explore paths such that if some paths have common part, we process this common part once -> Backtracking
 *
 * Name Backtracking means, we move to one of child state and process it, then BACK the TRACK we moved in, to try another path.
 *
 * Backtracking states actually make each recursive state as a graph node, and recursive call is directed edge and back of call is the edge reverse.
 *
 * Backtracking typically is written in recursive way, but could be written in iterative style (using stack)
 */
































/*
 * pseudocode
 *
 * Backtracking(state)
 * 		if invalid(state)	//e.g. we reached a # or the location is already visited
 * 			return
 *
 * 		if found_solution(state)
 * 			mark_solution_found
 * 			return
 *
 * 		for each child_state of state
 * 			state' = do changes in state
 *
 * 			Backtracking(state')
 *
 * 			state = undo changes in state'
 */






/*
 * Important to notice the pattern: do - rec - undo. It is typical in Backtracking
 *
 * Backtracking problems are little, but usually are hard.
 *
 * In hard problems, typically state is complicated to make algorithm efficient.
 *
 * Sometimes, you formulate the problem as Backtracking and got TLE, but it is actually a DP problem where saving states save time.
 */



























char maze[MAX_GRID][MAX_GRID];	// filled with S (for start), E (for end), . (could pass) and X (block can't path)
int pathsCnt = 0;
void countSEPaths(int r, int c)		// Recursion State: r, c
{
    if( maze[r][c] =='E')
    {
    	pathsCnt++;
    	return;
    }

	// Try the 4 neighbor cells
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    lp(d, 4)
    {
    	int nr = r+dx[d];
    	int nc = c+dy[d];

    	if(valid(nr, nc) && (maze[nr][nc] == '.' || maze[nr][nc] == 'E'))
    	{
    		if(maze[nr][nc] != 'E')			// do
    			maze[nr][nc] = 'X';

    		countSEPaths(nr, nc);			// rec

    		if(maze[nr][nc] != 'E')			// undo
    		    maze[nr][nc] = '.';
    	}
    }
}












// Note1: if grid just has S and E and ., the code will find exponential number of paths. O(Exponential)
// Note2: if problem asks for just is there a path, then you never do "undo step". Then code is called "FloodFill" NOT Backtracking. O(E+V)
// Note3: What about randomizing the 4 directions not passing in a systematic way 0, 1, 2, 3? Sometimes help if you target finding 1 path but have to do "undo"

// Homework: Write a simple code to implement string permutation using Backtracking. String abcd has 24 permutation.


































/*
 * Eight queens puzzle:
 * 		The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens attack each other.
 * 		Thus, a solution requires that no two queens share the same row, column, or diagonal (From wiki).
 *
 * 		General problem: N queens puzzle
 *
 * 	Initially you think solution is a tuple of 8 elements, each could take values from 1 - 8
 * 		Hence Order 8^8
 *
 * 	Fast note that we can't have items on same column, then actually we have a permutation -> Order (!8)
 * 		As we can't put on same row or diagonal, we know more search branches are deleted.
 *
 * 	The recursion is moving row by row, so we never duplicate row
 * 		In each time, we iterate over all columns to mark a column
 *
 * 	The recursion can easily has boolean array to mark visited column.
 *
 * 	What about diagonals! Each position mark 2 diagonals. An initial idea will be have 2d boolean for diagonal
 * 		Whenever position is selected, iterate over 2 diagonals and mark!	SO SLOW
 *
 * 	Hint! any diagonal have constant relation between row and column
 * 		use col+row and col-row to mark a selected diagonal		->		in Backtracking, you typically think in such things for faster code!
 */
























const int MAX = 8;

int ithRowQueen[MAX];
bool visited_col[MAX], diag_right[2*MAX+1], diag_left[2*MAX+1];

int sols = 1;

void Queens8(int r) 	// Recursion guarantee no same rows taken
{
	if(r == 8) //So we reach the end
	{
		// Print
		return;
	}

	for(int c=0; c<8; c++)			// j represent the column
	{
		if(!visited_col[c] && !diag_right[c+r] && !diag_left[MAX+c-r]) 	// Guarantee no repeated cols or diagonals
		{
			ithRowQueen[r] = c;

			visited_col[c] = diag_right[c+r] = diag_left[MAX+c-r] = 1;	// Do
			Queens8(r+1);
			visited_col[c] = diag_right[c+r] = diag_left[MAX+c-r] = 0;	//Undo
		}
	}
}
















/*
 * Little advanced:
 * 		1) The eight queens puzzle has 92 distinct solutions. If solutions that differ only by symmetry operations (reflections and rotations)
 * 			of the board are counted as one, the puzzle has 12 unique solutions.
 *
 *				Homework: HOW to use this symmetry property for implementing a bit more efficient solution?
 *
 *
 * 		2) N queens problem is an exact cover problem, and hence could be solved using Dancing Links for implementing AlgorithmX. Google if interested.
 */



























/*
 * So far, we refereed to 3 things that make search faster:
 *  1- Randomization trick (but rare)
 * 	2- Smart Data Structure to represent data (E.g. Diagonal for O(1) check)
 * 	3- Solution properties (e.g. symmetry in the queens puzzle solutions)
 *
 * 	The 4th trick, the hardest and adhock, is search with pruning. Idea is simple, but challenging per problem.
 *
 * 	Idea simply is, at the head of search you think in some way that you decide if going more is useless.
 * 		If you managed to do so, then you drop all these tree branches.
 *
 *  Pruning is the most dominant trick in most of hard problems.
 *
 *  Remember, it is adhock. You think in it per problem.
 *
 *  void search(state)
 *  	if hopeless(state)	return
 *
 *  	remain code
 */
















/*  Let's give an example. Say we want to solve the knapsack problem using backtracking. Please check it on wiki or our session in DP
 *
 *  Say data is
 *  	Profit:	10	25	5	13	50	8	5	4		2
 *  	Weight:	5	7	6	16	10	4	3	10		6
 *
 *	knapsack(curIdx, bestProfitSoFar, remainingWeight)
 * 		We simply in search have 2 choices, pick current item or leave it.
 *
 * 	Let's maintain a global integer that indicate best profit so far. We update it whenever we reach end and has better solution
 *
 * Say our search so far has best_global_profit = 80
 * Say we are now at position 5 (which has 8/4), and benefit so far is 48
 *
 * 		What could be our pruning?
 * 			Q: What is maximum possible benefit we could gain from this location regardless of our remaining weight?
 * 				Simply all remaining: 8+5+4+2 = 19	-> 48+19 = 67
 * 					Wait! Even if we took all of them, we will never update best_profit, which has value 80!
 * 					Drop this part. Do you know that we dropped 2^4 node!
 *
 */



























/*
 * The last trick! Data Sorting.
 * 		Sometimes, Search moves linearly, that is state has 1 index that it pass over it (e.g. queen row, knapsack curIdx)
 * 		Then we have the right to order data before tracing over it.
 * 		In queen, it seems useless, but in knapsack?
 *
 * 	What about ordering data such that bigger profit items are first?
 * 		E.g. profits ordered: 50 25 13 10 ...
 *
 * 		--> This will let the pruning works many times, as the more we took profit in the head, the remaining sum is smaller!
 *
 * 	What about ordering data such that bigger weight items are first + pick then leave NOT leave then pick?
 * 		E.g. weights: 16 10 10 7 ...
 *
 * 		--> This will decrease the remainingWeight highly in many times, hence we have to stop!
 */

// Notice that: when we pick first, we expcet a smaller depth in this tree than leave first. Especially when data sprted based on weight.
