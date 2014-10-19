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
const int OO = (int)1e6;
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














vector<int> BFS(int s, vector<vector<int> > & adjList) {
	vector<int> len(sz(adjList), OO);
	queue< pair<int, int> > q;
	q.push(MP(s, 0)), len[s] = 0;

	int cur, dep;
	while(!q.empty()) {
		pair<int, int> p = q.front();	 q.pop();
		cur = p.first, dep = p.second;

		rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
			q.push(MP(adjList[cur][i], dep+1)), len[adjList[cur][i]] = dep+1;
	}

	return len;	//cur is the furthest node from s with depth dep
}






























vector<int> BFS2(int s, vector<vector<int> > & adjList) {
	vector<int> len(sz(adjList), OO);
	queue<int> q;
	q.push(s), len[s] = 0;

	int dep = 0, cur = s, sz = 1;
	for (; !q.empty(); ++dep, sz = q.size()) {
		while (sz--) {
			cur = q.front(), q.pop();
			rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
				q.push(adjList[cur][i]), len[adjList[cur][i]] = dep+1;
		}
	}
	return len;	//cur is the furthest node from s with depth dep
}





















vector<int> BFSPath(int s, int d, vector<vector<int> > & adjList) {
	vector<int> len(sz(adjList), OO);
	vector<int> par(sz(adjList), -1);
	queue<int> q;
	q.push(s), len[s] = 0;

	int dep = 0, cur = s, sz = 1;
	bool ok = true;

	for ( ; ok &&  !q.empty();	++dep, sz = q.size()) {
		while (ok && sz--) {
			cur = q.front(), q.pop();
			rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
			{
				q.push(adjList[cur][i]), len[adjList[cur][i]] = dep+1, par[ adjList[cur][i] ] = cur;

				if(adjList[cur][i] == d)	// we found target no need to continue
				{
					ok = false;
					break;
				}
			}
		}
	}

	vector<int> path;
	while(d != -1) {
		path.push_back(d);
		d = par[d];
	}

	reverse( all(path) );

	return path;
}














// All is done by 1 BFS
// 1-1, 1-m
// m-1 -> Reverse it, start with target and go to sources
// m-m -> Set all start nodes in Q, and find targets

// Testing a graph for bipartiteness

// Edge Split, Vertex Split Tricks



// N=5
// 3	3
// 3 - 6, 6 - 7, 7 - 8
// in(3) = 3, out(3) = 8
// sp(1, 3) = sp( in(1), out(3)) = (1, 8)






























int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	int n, e;

	cin>>n>>e;

	vector<vector<int> > adj(n);

	lp(i, e) {
		int from, to;
		cin>>from>>to;
		adj[from-1].push_back(to-1);
 	}

	vector<int> p = BFSPath(0, 4, adj);
	rep(i, p)
		cout<<p[i]+1<<" ";

	return 0;
}
