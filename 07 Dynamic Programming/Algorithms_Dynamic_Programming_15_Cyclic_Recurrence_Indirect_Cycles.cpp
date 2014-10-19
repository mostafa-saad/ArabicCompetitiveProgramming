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

#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#define mp make_pair
#define pb push_back
#define Pair pair<int,int>

using namespace std;

int adj[1][1];
int n;

int shortestPath(int i, int j)
{
	int mn = adj[i][j];

	for(int k = 0; k < n; ++k) if(k != i && k != j)
		mn = min(mn, shortestPath(i, k) + shortestPath(k, j));

	return mn;
}

int floyd(int i, int j, int k)	// Recurrence redefinition
{
	if(k == 0)
		return adj[i][j];

	return min(floyd(i, j, k-1), floyd(i, k, k-1) + floyd(k, j, k-1));
}


/*
Let say we have a tree( N = 1600 node, each child has up to 4 children). We have a goal node, and
at each step we pick a neighbor to move to (even if visited before and even backing to may parent)

We want to calculate expected number of steps of each node to reach goal node.

A simple code that do it is
double exp(int cur)
{
   if(cur == target) return 0;
   for each child
       ret += (1/children) * exp(next child)

   return 1 + ret;
}

It is clear that calling a node will call me back sooner or later. And we can not mark visited nodes as it violates required.

Let's give each state a variable name. E.g. A0 means first node, A1 2nd....

Let's mathematically formulate the above call

	Say in exp(cur) cur is 3. And it will call 3 children, 4, 5, 8. Let p = 1/3, probability of choice

	Then A3 = 1 + p*A4 + p*A5 + p * A8
		Reformulate: A3 - p*A4 - p*A5 - p * A8 = 1

	Do so for each possible state. Now you have N variables and N equations. Run


What about mathematical equations.
let say we have cs=3 children
A = ( (C[0]+1) + (C[1]+1) + (C[2]+1) ) / cs = 1 + C[0]/cs+C[1]/cs+C[2]/cs
Reformulate:
C[0]/cs + C[1]/cs + C[2]/cs - A = 1

And so on for each node

For starting node A[goal] = 0

Run Gaussian elimination and get answer of any state. Note, matrix is sparse, so probably will be O(n^2) not O(n^3) for smart implementation.

Finally, when Equation is of 2/3 variables only, it may be solved linearly in adhock way. If matrix is Tridiagonal, an O(N) standrad algorithm exist.


 */



int main()
{
	return 0;
}
