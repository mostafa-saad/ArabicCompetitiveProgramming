/*
 * 294A.cpp
 *
 *  Created on: Feb 1, 2014
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














int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif















	// Simulation problem: Just simulate the target problem

	const int MAX = 100;
	int birds[MAX];

	int n;
	cin>>n;

	for(int i = 0; i < n; ++i)
		cin>>birds[i];

	int m;
	cin>>m;

	for(int i = 0; i < m; ++i)
	{
		int x, y;
		cin>>x>>y;
		--x;	// x input is 1 based. we need it 0-based to access array

		//kill yth bird in xth position: (y-1 items, y, a-y)

		if(x != 0)							// if there exists no upper wire they fly away.
			birds[x-1] += y-1;				// scared and jump up

		if(x != n-1)
			birds[x+1] += birds[x] - y;		// scared and jump down

		birds[x] = 0;	// now it is empty
	}

	for(int i = 0; i < n; ++i)
		cout<<birds[i]<<"\n";

	return 0;
}
