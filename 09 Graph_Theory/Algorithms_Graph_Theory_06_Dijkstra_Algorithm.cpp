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

















/*
 * Facts:
 *
 * Single-source shortest-paths problem: From one source s, find SP to all other nodes
 *
 * To solve single-destination shortest-paths problem: Reverse edges direction = single-source problem.
 *
 * A shortest path between two vertices contains other shortest paths within it.
 * 		E.g. SP(2, 7) = 2-4-3-8-7	-> SP(4, 8) = 4-3-8
 *
 * For a given source s, the set of shortest paths from s to other n-1 nodes, construct a tree, called SP tree
 *
 * In a graph of N nodes, longest path will have N-1 edges. If not it will have cycle, then not SP!
 *
 * A shortest path will never have a cycle (+ve or -ve)
 *
 * If there is a -ve cycle C, and s reaches C, and C reaches d -> The SP(s, d) = -OO
 *
 * Some algorithms could handle -ve cycles (e.g. Floyd, Bellman), Others Can't (e.g. Dijkstra)
 *
 * Relaxation is good! Say so far we go from (2, 7) = 20. We know too that (2, 3) = 5 and (3, 7) = 12
 *
 * 		Then we could RELAX path to take other way, then (2, 7) = min( (2, 7), (2, 3) + (3, 7) ) = 17
 */

















/*
 *  Say we have nonnegative weighted graph of n nodes, and a source node s. Could you find just the sp to 1 node.
 *
 *  Yes, pick smallest edge from the s!
 */



/*
 * Say we have graph of n nodes. We want to remove node X, but we need the graph doesn't miss any information about paths!
 *
 * If node has A edges entering it, and B edges outing it -> Add A * B edges, then we don't miss any info.
 *
 * What if care with info according to only 1 certain node! Then add B edges only for this node.
 */

/*
 * Dijkstra Algorithm:
 *
 * As long as remain nodes
 * 		1- Pick non visited node with minimum cost
 * 		2- Relax Graph using this node (as if node is removed and its info is distrusted to graph
 */





















int Dijkstra1(vector< vi > adjMax, int src, int dest = -1)	// O(n^2)
{
	int n = sz(adjMax);
	vi vis(n, 0), dist(n, OO), prev(n, -1);
	dist[src] = 0;

	while(true) {
		int val = OO, idx = -1;
		lp(i, n)
			if(!vis[i] && dist[i] < val)	val = dist[i], idx = i;

		if(idx == -1 || idx == dest)	break;
		vis[idx] = 1;

		lp(i, n)
			if (dist[i] > (val=dist[idx] + adjMax[idx][i]) )
				dist[i] = val, prev[i] = idx;	// Relax
	}
	return dest == -1 ? -1 : dist[dest];
}

























struct edge {
	int from, to, w;

	edge(int from, int to, int w): from(from), to(to), w(w) {}

	bool operator < (const edge & e) const {
		return w > e.w;
	}
};

int Dijkstra2(vector< vector< edge > > adjList, int src, int dest = -1)	// O(E logV)
{
	int n = sz(adjList);
	vi dist(n, OO), prev(n, -1);
	dist[src] = 0;

	priority_queue<edge> q;
	q.push( edge(-1, src, 0) );

	while( !q.empty() ) {
		edge e = q.top();	q.pop();

		if(e.w > dist[e.to])	continue;	// some other state reached better

		prev[ e.to ] = e.from;

		rep(j, adjList[e.to]) {
			edge ne = adjList[e.to][j];
			if( dist[ne.to] > dist[ne.from] + ne.w ) {
				ne.w = dist[ne.to] = dist[ne.from] + ne.w;
				q.push( ne );
			}
		}
	}

	return dest == -1 ? -1 : dist[dest];
}




int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	return 0;
}
