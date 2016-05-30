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
#include<algorithm>
#include<stdio.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef long double ld;

const int MAXN = 1000;


int adjMat[MAXN][MAXN];
int low[MAXN], dfn[MAXN], num, n;
vector<pair<int, int> > bridges;

void art_bridges(int i, int p) {
	low[i] = dfn[i] = ++num;

	for (int j = 0; j < n; ++j) if (adjMat[i][j] && j != p) {
		if (dfn[j] == 0) {
			art_bridges(j, i);
			low[i] = min(low[i], low[j]);
			if (low[j] == dfn[j])
				bridges.push_back(make_pair(min(i, j), max(i, j)));
		} else
			low[i] = min(low[i], dfn[j]);
	}
}

void run_art_bridges() {
	lp(i, n)	low[i] = -1, dfn[i] = 0;

	bridges.clear();

	lp(i, n) if (!dfn[i])
		art_bridges(i, -1);

	sort(all(bridges));

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
#endif

	int to, cnt, from;
	char ch;

	while (cin >> n) {

		lp(i, n) lp(j, n)
			adjMat[i][j] = 0;

		lp(i, n) {
			cin >> from >> ch >> cnt >> ch;
			lp(j, cnt) {
				cin >> to; //0-based
				adjMat[from][to] = 1;
			}
		}

		run_art_bridges();

		cout << bridges.size() << " critical links\n";
		rep(i, bridges)
			cout << bridges[i].first << " - " << bridges[i].second << "\n";

		cin >> ws;
		cout << "\n";

	}
	return 0;
}
