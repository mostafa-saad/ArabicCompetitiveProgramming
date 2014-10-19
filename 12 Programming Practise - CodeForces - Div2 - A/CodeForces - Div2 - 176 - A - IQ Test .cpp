/*
 * 278A.cpp
 *
 *  Created on: Jan 28, 2014
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













char inp[4][4];

bool test(int i, int j)
{
	if(i+1 == 4 || j+1 == 4)	// don't access outside array
		return false;

	//make sure the 4 cells are equal
	return inp[i][j] == inp[i][j+1] && inp[i][j] == inp[i+1][j] && inp[i][j] == inp[i+1][j+1];
}

bool test()
{
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
			if(test(i, j))
				return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
#endif

	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
			cin>>inp[i][j];
	}


	bool weDidIt = test();

	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			char original = inp[i][j];

			// Do Flip
			if(inp[i][j] == '.')
				inp[i][j] = '#';
			else
				inp[i][j] = '.';

			if(test())
				weDidIt = true;

			inp[i][j] = original;
		}
	}

	if(weDidIt)
		cout<<"YES";
	else
		cout<<"NO";

	return 0;
}
