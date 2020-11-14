/*
 * 10617.cpp
 * Another buggy code by mostafa_saad
 *
 *  Created on: Oct 17, 2008
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
#include<algorithm>
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

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef long long         ll;
typedef long double   	  ld;

const int OO = (int)1e8;	//Small -> WRONG, Large -> OVERFLOW

const double PI  = acos(-1.0);
const double EPS = (1e-7);

int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

string str;
ll memo[100][100];

ll best(int i, int j) {
	if(i == j)		return 1;
	if(i+1 == j)	return 2 + (str[i] == str[j]);	// handle length=2 as special case

	ll &ret = memo[i][j];
	if(ret != -1)	return ret;

	ret = 0;
	if(str[i] == str[j])
		ret += best(i+1, j-1) +1;	// +1 for the container palindrome when body is empty

	ret += best(i+1, j);
	ret += best(i, j-1);
	ret -= best(i+1, j-1);	// remove duplication of (i+1, j), (i, j-1)

	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
#endif

	int cases;
	cin>>cases;

	while(cases--)
	{
		cin>>str;
		clr(memo, -1);

		cout<<best(0, sz(str)-1)<<"\n";

	}

	return 0;
}
