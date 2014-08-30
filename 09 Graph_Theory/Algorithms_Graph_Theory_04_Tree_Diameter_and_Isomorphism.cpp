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


// http://www.spoj.com/problems/TREEISO/
// http://www.spoj.com/problems/TRANSL/


// tree center: max 2 centers.
// http://www.spoj.com/problems/PT07Z/









































vector< vector<int> > adjLst;

// There are some nodes that must be part of the diameter
// Diameter either pass with me (sum of 2 highest sub-trees) or don't, then diameter pass with a children
// return pair(diameter, height)
pair<int, int> diameter(int i, int par = -1)
{
	int diam = 0;
	int mxHeights[3] = {-1, -1, -1};	// keep 2 highest trees

	rep(j, adjLst[i]) if(adjLst[i][j] != par)
	{
		pair<int, int> p = diameter(adjLst[i][j], i);
		diam = max(diam, p.first);

		// Keep only the 2 maximum children
		mxHeights[0] = p.second+1;
		sort(mxHeights, mxHeights+3);
	}

	lp(i, 3) if(mxHeights[i] == -1)
		mxHeights[i] = 0;

	diam = max(diam, mxHeights[1] + mxHeights[2]);

	return make_pair(diam, mxHeights[2]);
}




// If tree is weighted, same algorithm, just modify the costs
// this algorithm doesn't work for graphs, but gives good approximation















/*
 	One of popular algorithms, although no formal source for proving is 2 BFS idea:

    1- Select a random node A
    2- Run BFS on this node to find furthermost node from A. name this node as S.
    3- Now run BFS starting from S, find the furthermost node from S, name it D.
    4- Path between S and D is diameter of the tree.

 */

























/*
 * One of applications of tree diameter is finding tree centers
 * 		the nodes in the tree that minimize the length of the longest path from it to any other node.
 *
 * If diameter length is even, then we have one tree center. If odd, then we have 2 centers.
 *
 * E.g. 1-2-3-4-5	-> center is 3
 * E.g. 1-2-3-4-5-6	-> center is 3, 4
 *
 * On other side, we can get the worst nodes through the center nodes.
 * A worst node is one that is an end of a diameter, so it has the worst tree height
 */















// tree isomorphism

// Given 2 trees and roots for each one, are they isomorphism?
// dfs(tree1, tree2)

// General Method: compare(object1, object2) -> Canonical(object1) == Canonical(object2)


/*
 * Graph (1-2, 1-3) and root 1
 * 			1
 * 		2		3
 *
 * 		2 is () and 3 is ()
 * 		1 is ( () () )
 *
 *
 * Graph (1-2, 1-3, 4-1, 4-5) and root 4
 *
 *
 *
 * 		5
 * 	2		3
 * 		4		1
 *
 * 		2, 3, and 5 are ()
 * 		1 is ( () () )
 * 		4 is ( ( () () )  () )
 */













string treeCanoincalForm(int i, int par)
{
	vector<string> childern;

	rep(j, adjLst[i]) if(adjLst[i][j] != par)
		childern.push_back( treeCanoincalForm(adjLst[i][j], i) );

	string nodeRep = "(";
	sort( all(childern) );
	rep(k, childern)
		nodeRep += childern[k];
	nodeRep += ")";

	return nodeRep;
}









// What if no roots? Find roots! Tree has 1 or 2 centers maximum. so we may need maximum to 4 canonical form to compare
// Let's tree other way





















string getNodeCanoincalForm(int v, vector< vector<string> > &subCan)	// we could use hashing for a better performance
{
	string nodeRep = "(";
	sort( all(subCan[v]) );
	rep(i, subCan[v])
		nodeRep += subCan[v][i];
	nodeRep += ")";

	return nodeRep;
}

/*
 * Tree shrinking algorithm. Each time leaves shrink toward their parents.
 */
string treeCanoincalForm()	// assumes tree not forest
{
	int n = sz(adjLst);

	// Prepare level one nodes: the leaves
	queue<int> LeafNodes;
	vector<int> deg(n, -1);
	int remNodes = n;

	rep(i, adjLst) {
		if(sz(adjLst[i]) <= 1)
			LeafNodes.push(i);
		else
			deg[i] = sz(adjLst[i]);
	}

	vector< vector<string> > subCan(n);

	while(remNodes > 2)	// bfs-like
	{
		int sz = sz(LeafNodes);
		while(sz--)	// level by level
		{
			int v = LeafNodes.front();			LeafNodes.pop();

			string nodeRep = getNodeCanoincalForm(v, subCan);

			rep(j, adjLst[v]) {
				int to = adjLst[v][j];
				subCan[to].push_back(nodeRep);
				if(--deg[to] == 1)
					LeafNodes.push(to);
			}
			--remNodes;
		}
	}

	// what remains are tree centers
	int v1 = LeafNodes.front();			LeafNodes.pop();
	int v2 = LeafNodes.empty() ? -1 : LeafNodes.front();

	string str1 = getNodeCanoincalForm(v1, subCan);
	string str2 = v2 == -1? "" : getNodeCanoincalForm(v2, subCan);

	if(v2 == -1)	// only 1 node
		return str1;

	// 2 nodes. try 2nd as child of first and reverse
	subCan[v1].push_back(str2);
	subCan[v2].push_back(str1);

	return min(getNodeCanoincalForm(v1, subCan), getNodeCanoincalForm(v2, subCan));
}


























int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	int n;
	scanf("%d", &n);
	adjLst = vector< vector<int> > (n);

	lp(i, n-1)
	{
		int f, t;
		scanf("%d %d", &f, &t);
		--f, --t;

		adjLst[f].push_back(t);
		adjLst[t].push_back(f);
	}

	cout<<treeCanoincalForm();

	return 0;
}
