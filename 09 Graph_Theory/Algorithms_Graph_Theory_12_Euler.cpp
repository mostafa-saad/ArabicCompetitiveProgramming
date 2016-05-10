#include<set>
#include<map>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repit(i, c)       	for(typeof(c) i = (c).begin(); i != (c).end(); ++i)
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector<string>    vs;	
typedef long long         ll;
typedef long double   	  ld;

const int OO = (int)1e8;	// Note, IF Small may be WRONG, Large may generate OVERFLOW

void euler(vector< vi > & adjMax, vi & ret, int n, int i, bool isDirected = false) {
	lp(j, n) {
		if(adjMax[i][j]) {
			adjMax[i][j]--;
			if(!isDirected)		adjMax[j][i]--;
			euler( adjMax, ret, n, j, isDirected );
		}
	}
	ret.push_back( i );
}

//In case graph of 1 node?
pair<int, vi> undirectedEuler( vector< vi > adjMax) 
{	// adjMax[i][j] is #of arcs between i, j
	int notConnected = -2, invalid = -1, cycle = 0, path = 1, n = sz(adjMax), anyNode = -1;
	int edgesCnt = 0, status;
	
	vi deg(n, 0), ret;
	repa(adjMax) if(i<=j && adjMax[i][j]) {
		if(i == j)	adjMax[i][j] /= 2;	// self loops adds itself twice
		deg[i] += adjMax[i][j], deg[j] += adjMax[i][j], edgesCnt += adjMax[i][j];
		if(i == j)	adjMax[i][j] *= 2;	// self loops adds itself twice
	}
		
	vi odds;
	lp(i, n)  {
		if( deg[i]%2 ) odds.push_back( i );
		if( deg[i] && anyNode == -1 )	anyNode = i;
	}

	if( odds.size() == 1 || odds.size() > 2)	status = invalid;
	else if( odds.size() == 2) {
		status = path;	 	euler(adjMax, ret, n, odds[0]);
	}
	else {
		status = cycle;		 if(anyNode != -1) euler(adjMax, ret, n, anyNode);
	}
	
	if(sz(ret) && edgesCnt != sz(ret)-1)		status = notConnected;
	reverse( all(ret) );
	return make_pair(status, ret);
}

// I think below code doesn't handle all cases. TODO.

pair<int, vi> directedEuler( vector< vi > & adjMax)
{	// adjMax[i][j] is #of arcs between i, j
	int invalid = -1, cycle = 0, path = 1, n = sz(adjMax), anyNode = -1, inNode = -1, outNode = -1, status;
	int notConnected = -2, edgesCnt = 0;

	vi indeg(n, 0), outdeg(n, 0), ret;
	repa(adjMax) if(adjMax[i][j]) 
		outdeg[i] += adjMax[i][j], indeg[j] += adjMax[i][j], edgesCnt += adjMax[i][j];
	vi odds;
	lp(i, n)  {
		if( indeg[i]+outdeg[i] ) {
			if(indeg[i] == outdeg[i]) 	anyNode = i;
			else {
				odds.push_back( i );
				if(indeg[i] == outdeg[i]+1)	inNode  = i;
				else if(indeg[i] == outdeg[i]-1)			outNode = i;
			}
		}
	}
	if( odds.size() == 1 || odds.size() > 2)	status = invalid;
	else if( odds.size() == 2) {
		if(inNode != -1 && outNode != -1) {                                                                                                                                            
			status = path;	 	euler(adjMax, ret, n, outNode, 1);
		} else
			status = invalid;
	}
	else {
		status = cycle;		 if(anyNode != -1) euler(adjMax, ret, n, anyNode, 1);
	}
	if(sz(ret) && edgesCnt != sz(ret)-1)		status = notConnected;
	reverse( all(ret) );
	return make_pair(status, ret);
}

/*
	Euler Formula
If a connected planer graph is drawn in the plane with
no crossings, then f - e + v = 2
Where f: #faces, e: #edges v: #vertices

if graph disconnected
f = 2 - v + e + num_components(v) - 1 // -1 for border face
*/
