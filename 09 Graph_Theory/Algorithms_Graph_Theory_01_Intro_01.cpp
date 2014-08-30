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


const int N = 100;

// adjacency matrix
bool adjMatrixBool[N][N];
int adjMatrix[N][N];

vector<int>	adjMatrixAll[N][N];		// Keep all edges for a given pair of nodes

map< pair<int, int>, int> adjMatrixMap;	// Imagine graph of 100000 node, but total number of edges is 50000!


// Adjacency lists
vector< vector<int> > adjList1;					// boolean relation
vector< vector< pair<int, int> > > adjList2;	// cost relation (node, cost): Select 1 of multiple edges


// Edges List
struct edge {
	int from, to, w;

	edge(int from, int to, int w): from(from), to(to), w(w) {}

	bool operator < (const edge & e) const {
		return w > e.w;	// Sort with smaller weight first
	}
};

vector<edge> edgeList;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif
	int n;

	// Assume all input is ZERO based. Node values [0 - n-1]

	/*
	 	3
		0 1 0
		1 1 0
		0 1 1
	 */

	cin>>n;
	lp(i, n) lp(j, n)	{
		int b;
		cin>>b;
		adjMatrixBool[i][j] = b;
	}

	/*
		3
		0 10 5
		2 7 9
		3 2 0
	 */

	cin>>n;
	lp(i, n) lp(j, n)	{
		int b;
		cin>>b;
		adjMatrix[i][j] = b;
	}

	//adjMatrix initialize with OO
	int edges;
	cin>>n>>edges;
	/*
	 	 3 5
	 	 0 3 10
	 	 1 5 2
	 	 3 7 -2
	 	 0 3 2
	 	 2 4 6
	 */
	lp(i, edges)
	{
		int from, to, cost;
		cin>>from>>to>>cost;
		adjMatrix[from][to] = min(adjMatrix[from][to], cost);	// if directed

		// if undirected: add following
		adjMatrix[to][from] = adjMatrix[from][to];
	}



	// Let's keep edge with min cost;

	/*
		3
		2	1 2
		1	2
		2	0 1
	 */
	cin>>n;
	adjList1 = vector< vector<int> >(n);
	lp(i, n)
	{
		int cnt;
		cin>>cnt;
		lp(j, cnt)
		{
			int to;
			cin>>to;
			adjList1[i].push_back(to);
		}
	}

	/*
		3
		2	1 13	2 4
		1	2 9		3 -4
		2	0 -7	1 8
	 */
	cin>>n;
	adjList2 = vector< vector< pair<int, int> > >(n);
	lp(i, n)
	{
		int cnt;
		cin>>cnt;
		lp(j, cnt)
		{
			int to, cost;
			cin>>to>>cost;
			adjList2[i].push_back( make_pair(to, cost));
		}
	}

	return 0;
}











