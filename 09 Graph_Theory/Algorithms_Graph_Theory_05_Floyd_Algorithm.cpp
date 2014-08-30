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



const int OO = (int)1e6;

const int MAX = 20;
int adj[MAX][MAX];
int dp[MAX+1][MAX][MAX];
int n;








/*
 * Single source Shortest path
 * All Pairs Shortest path
 */














int shortestPath(int i, int j)	// cyclic recurrence
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












// This is memoized in O(n^3)

void floyd1()
{
	lp(i, n) lp(j, n)
		dp[0][i][j] = adj[i][j];

	lp(k, n) lp(i, n) lp(j, n)
		if(dp[k][i][k] < OO && dp[k][k][j] < OO)
			dp[k+1][i][j] = min(dp[k+1][i][j], dp[k][i][k]+dp[k][k][j]);

	// dp[n] is the shortest path 2d array
}
























void floyd2()
{
	// 0 - Infinity MUST be larger than any path. Say we have n = 1000, and cost of edge max 5000, then min OO to = (1000-1) * 5000 + 1
	// 1- Set whole array to infinity:
	// 2- read input edges
	// 3- set diagonal to zeros: sometimes, if negative input you would like to leave them: e.g. adj[3][3] = -7 -> a self cycle

	// k: Incrementally add new node and update matrix
	lp(k, n) lp(i, n) lp(j, n)
		if(adj[i][k] < OO && adj[k][j] < OO)	// you could remove this line IFF 2*OO fit in the data type.
			adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

	// an order lp(i, n) lp(j, n) lp(k, n)		is wrong translation

	// What if we need to get the path? 2 ways

	// Define path arr, initialize it to -1, which means direct
	// If path (i, j) has intermediate node k, then path[i][j] = k; means path from i to j pass with k
	// Write a recursive function be like:
	/*
	 void build_path(int src, int dest)
	{
		if( path[src][dest] == -1 )	//So this is the last way
		{
			// print
			return;
		}
		build_path( src, path[src][dest]);
		build_path( path[src][dest], dest);
	}
	 */

	// Other way is through previous of path: prev[i][j]: last node before j from i to j
	// Initialize repv[i][j] = i
	// If path (i, j) has intermediate node k, then prev[i][j] = prev[k][j];
	// Write a recursive function be like:
	/*
	 void printPath(int i, int j)
	 {
		if (i != j)
			printPath(i, prev[i][j]);
		printf(" %d", j);
	}
	*/
}
















void TransitiveClosure()
{
	// assume matrix is 0 for disconnect, 1 is connect
	// we only care if a path exist or not, not a shortest path value

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] |= (adj[i][k] & adj[k][j]);
}

void minimax()
{
	// find path such that max value on road is minimum

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]) );
}

void maximin()
{
	// find path such that min value on road is maximum

	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]) );
}

void longestPathDAG()
{
	lp(k, n) lp(i, n) lp(j, n)
		adj[i][j] = max(adj[i][j], max(adj[i][k], adj[k][j]) );
}

void countPaths()
{
	lp(k, n) lp(i, n) lp(j, n) 	// Floyd warshal for counting #of paths
		adj[i][j] += adj[i][k] * adj[k][j];

	// 1- assume graph is DAG
	/*
	 * k = 5, i = 1, j = 2 we will use adj[ 1 ][ 5 ] with old value
	 * k = 5, i = 1, j = 5 we will update adj[ 1 ] [ 5 ]
	 * k = 5, i = 1, j = 7 we will use adj[ 1 ][ 5 ] with new value
	 * Won't this give and incorrect result?
	 *
	 * NO. E.g. when k = 5, i = 1, j = 5:
	 * adj[1][5] += adj[1][5] * adj[5][5];
	 * adj[5][5] = 0, so no update happens. In general, when k = i or j, no updates happens, so in-placement update is fine.
	 */

	/*
	 * What if graph is not DAG.
	 * if(adj[i][i] > 0)	-> i has a cycle path on it
	 *
	 * Generally, for any node v that has a cycle,
	 * 		if i reaches v, and v reaches j, then count of (i, j) is useless as count is OO. Remain adj[][] is valid
	 */

}










/*
 * . If you had a cycle in a graph, the longest path wouldn't be
well defined, because you could keep going round and round the cycle
making the path longer.
 */

bool isNegativeCycle() {
	lp(i, n)
		if(adj[i][i] < 0)
			return true;	// then node i got to i with overall cost < 0.

	return false;
}

bool anyEffectiveCycle(int src, int dest)
{
	lp(i, n)
		if(adj[i][i] < 0 && adj[src][i] < OO && adj[i][dest] < OO)
			return true;

	return false;	// there is a finite path although cycles if any
}


























/*
 * Graph negative:
 * 	Shortest <-> Longest
 * 	Postive Cycle <-> Negative Cycle
 * 	Minimax <-> Maximin
 */























int graphDiameter()
{	// Longest path among all shortest ones

	floyd2();

	int mx = 0;
	lp(i, n) lp(j, n) if(adj[i][j] < OO)
		mx = max(mx, adj[i][j]);

	return mx;
}















vector< vector<int> > SCC()
{
	vector<int> comp(n, -1);

	int cnt = 0;
	lp(i, n) if(comp[i]==-1) {
		comp[i] = cnt++;
		lp(j, n) if(adj[i][j] < OO && adj[j][i] < OO)	// transitive clusre is enough
			comp[j] = comp[i];
	}

	vector< vector<int> > compGraph(cnt, vector<int>(cnt));

	lp(i, n) lp(j, n)	if(adj[i][j] < OO)
		compGraph[ comp[i] ][ comp[j] ] = 1;	// DAG

	return compGraph;
}




















int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	return 0;
}
