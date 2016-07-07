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

const int MAX = 100;
bool valid(int i, int j) { 	return 1;	}
char maze[MAX][MAX];
bool vis[MAX][MAX];


















int n, e;
vector< vector<int> > adj;
vector<bool> visited;

vector<int> topsort;
vector<int> start, finish;
bool anyCycle = 0;
int timer = 0;




void dfs(int node)
{
	visited[node] = true;

	rep(i, adj[node])
	{
		int child = adj[node][i];
		if (!visited[child])	// To avoid cyclic behavior
			dfs(child);
	}

	topsort.push_back(node);	// DAG // Other way Indegree / Outdegree
}



















int ConnectedComponenetsCnt()
{
	int cnt = 0;
	lp(i, n)
	{
		if(!visited[i])	// Then no one reach this isolated node yet and its neighbors.
		{
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}

























void dfs_EdgeClassification(int node)
{
	start[node] = timer++;

	rep(i, adj[node])
	{
		int child = adj[node][i];
		if (start[child] == -1)	// Not visited Before. Treed Edge
			dfs_EdgeClassification(child);
		else {
			if(finish[child] == -1)// then this is ancestor that called us and waiting us to finish. Then Cycle. Back Edge
				anyCycle = 1;
			else if(start[node] < start[child])	// then you are my descendant
				;	// Forward Edge
			else
				;	// Cross Edge
		}
	}

	finish[node] = timer++;
}








































// Flood Fill...given maze where cells are . or X. You start at 0, 0..how many cells you could reach?
/*
..X.
.X.X
..X.

...x.
..x..
.x...
x....


....X...
....XXXX
..X.....
.X....XX
..X.X.X.
..X...X.
...X..XX
*/

// A reachable block is called connected components. Each set of positions reachable together are connected component.


int cnt = 0;
void cntReachalbleCells(int r, int c)
{
    if( !valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
		return;		// invalid position or block position


	vis[r][c] = 1;	// we just visited it, don't allow any one back to it
	cnt++;

	// Try the 4 neighbor cells
	cntReachalbleCells(r, c-1);
    cntReachalbleCells(r, c+1);
    cntReachalbleCells(r-1, c);
    cntReachalbleCells(r+1, c);
}





int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif


	cin>>n>>e;

	adj = vector< vector<int> >(n);
	visited = vector<bool>(n);
	start = vector<int>(n, -1);
	finish = vector<int>(n, -1);

	lp(i, e) {
		int from, to;
		cin>>from>>to;
		adj[from-1].push_back(to-1);
 	}

	lp(i, n) if(start[i] == -1)
		dfs_EdgeClassification(i);

	cout<<anyCycle;


	return 0;
}
