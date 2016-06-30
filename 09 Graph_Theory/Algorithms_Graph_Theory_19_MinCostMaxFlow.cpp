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
#define repit(i, c)       	for(it(c) i = (c).begin(); i != (c).end(); ++i)
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

struct edge {
	int from, to, w;
	
	edge(int from, int to, int w): from(from), to(to), w(w) {}
	
	bool operator < (const edge & e) const {
		return w > e.w;	// STL priority_queue need it > , or modify data -ve, or use paprmeter less
	}
};

bool BellmanPrcoessing(vector<edge> & edgeList, int n, vi &dist, vi &prev, vi &pos) {
	if(sz(edgeList) == 0)	return false;

	//vi dist(n, OO), prev(n, -1), pos(n);	// To use pos: edgeList[pos[path[i]]].w
	//dist[ edgeList[0].from ] = 0;

	for (int it = 0, r = 0; it < n+1; ++it, r = 0) {
		for (int j = 0; j < sz(edgeList) ; ++j) {
			edge ne = edgeList[j];
			if(dist[ne.from] >= OO || ne.w >= OO)	continue;
			if( dist[ne.to] > dist[ne.from] + ne.w ) {
				dist[ne.to] = dist[ne.from] + ne.w;
				prev[ ne.to ] = ne.from, pos[ ne.to ] = j, r++;
				if(it == n)		return true;
			}
		}
		if(!r)	break;
	}
	return false;
}

pair<vi, vi> BellmanFord(vector<edge> & edgeList, int n, int src, int dest)	// O(NE)
{
	vi dist(n, OO), prev(n, -1), reachCycle(n), path, pos(n);	// To use pos: edgeList[pos[path[i]]].w
	dist[src] = 0;

	bool cycle = BellmanPrcoessing(edgeList, n, dist, prev, pos);

	if(cycle) {
		vi odist = dist;
		BellmanPrcoessing(edgeList, n, dist, prev, pos);
		for (int i = 0; i < n; ++i)	// find all nodes that AFFECTED by negative cycle
			reachCycle[i] = (odist[i] != dist[i]);
	} else
		path = buildPath(prev, dest);

	return make_pair(dist, path);
}


// Set cost & cap arr to ZERO
// Make sure that for each cost[i][j] += c there exist cost[j][i] -= c and cap[i][j] += flow
// lp(i, r)	cap[0][i+1]=1;	lp(j, c) cap[j+r+1][r+c+1]=1;	lp() cap[i+1][j+r+1] = 1
// MaxCostMaxFlow can be obtained by multiplying cost matrix(initially zeros) by -1.
// The algo will not work if there is negative cycle reachble on road from src to dest [not tested]
pair<int, int> mcmf(vector< vi > capMax, vector< vector<int> > & costMax, int src, int dest) 
{
	int maxFlow = 0, minCost = 0;
	while(true) {
		vector<edge> edgeList;
		repa(capMax) if(capMax[i][j] > 0) edgeList.push_back( edge(i, j, costMax[i][j]) );
		
		pair<vi, vi> p = BellmanFord1(edgeList, sz(capMax), src, dest);
		if(p.first[dest] <= -OO || p.first[dest] >= +OO)	break;

		int bottleNeck = OO;
		lp(i, sz(p.second)-1 ) {
			int f = p.second[i], t = p.second[i+1];
			bottleNeck = min(bottleNeck, capMax[f][t]); 
		}

		lp(i, sz(p.second)-1 ) {
			int f = p.second[i], t = p.second[i+1];
			minCost += bottleNeck * costMax[f][t];
			capMax[f][t] -= bottleNeck, capMax[t][f] += bottleNeck;
		}
		maxFlow += bottleNeck;
	}
	return make_pair(maxFlow, minCost);
}
