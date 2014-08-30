/*
 * prim.cpp
 *
 *  Created on: Jul 28, 2013
 *      Author: Mostafa Saad
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


struct edge {
	int from, to, w;

	edge(int from, int to, int w): from(from), to(to), w(w) {}

	bool operator < (const edge & e) const {
		return w > e.w;	// STL priority_queue need it > , or modify data -ve, or use paprmeter less
	}
};








// Find MST value & edges. adjMax is initialized by OO
pair<int, vector<edge> > PRIM_MST1(vector< vi > adjMax)	// O(n^2)
{
	int curNode = 0, n = sz(adjMax), mini;
	int mind, mstCost = 0;

	vi vis(n, 0), prev(n);
	vi dist(n, OO); // 1) dist[i]: Minimum value to connect i to current built tree
	vector<edge> edges;			 // Save MST edges

	lp(k, n-1)
	{
		vis[curNode] = 1, mind = OO, mini = -1;
		lp(i, n)
		{
			if(!vis[i])
			{
				if(adjMax[curNode][i] < dist[i])	//2) Update if i can reach tree with a new Minimum value
					dist[i] = adjMax[curNode][i], prev[i] = curNode;

				if (dist[i] < mind) mind = dist[i], mini = i;	//3) Select minimum EDGE value
			}
		}
		if(mini == -1)	break;	// 4) check if graph is disconnected
		// 5) update edges and cost of mst
		edges.push_back( edge(prev[mini], mini, adjMax[prev[mini]][mini] ) );
		curNode = mini, mstCost += dist[curNode];
	}

	if( sz(edges) != n-1)	return make_pair(OO, vector<edge>() );
	return make_pair(mstCost, edges);
}















pair<int, vector<edge> > PRIM_MST2(vector< vector< edge > > adjList) // O(E logV)
{	// edge x-->y & y-->x	must be in the adjList
	int n = sz(adjList), mstCost = 0;
	vi vis(n, 0);
	vector<edge> edges;			 // Save MST edges

	priority_queue<edge> q;		// 1) priority_queue to sort edges
	q.push( edge(-1, 0, 0) );

	while( !q.empty() ) {
		edge e = q.top();		q.pop();
		if( vis[e.to] )	continue;
		vis[e.to] = 1;
		mstCost += e.w;
		if(e.to)	edges.push_back( e );	// 2) remove min element & update cost/list

		rep(j, adjList[e.to]) {				// 3) Iterate on adjacent edges & add new edges, using e.to as src
			edge ne = adjList[e.to][j];
			if( !vis[ ne.to] )				// 4) If added will cause cycle
				q.push( ne );
		}
	}

	if( sz(edges) != n-1)	return make_pair(-OO, vector<edge>() );
	return make_pair(mstCost, edges);
}














int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	return 0;
}
