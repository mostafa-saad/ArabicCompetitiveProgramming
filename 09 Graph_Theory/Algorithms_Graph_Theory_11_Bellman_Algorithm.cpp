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

vi buildPath(vi prev, int src) {
	vi path;	// make sure to test case self edge. E.g. 2 --> 2
	for (int i = src; i > -1 && sz(path) <= sz(prev); i = prev[i])	
		path.push_back(i);
	reverse( all(path) );
	return path;
}

bool BellmanPrcoessing(vector<edge> & edgeList, int n, vi &dist, vi &prev, vi &pos) {
	if(sz(edgeList) == 0)	return false;

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

pair<int, bool> BellmanFord(vector<edge> & edgeList, int n, int src, int dest)	// O(NE)
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

	return make_pair(dist[dest], cycle);
}
