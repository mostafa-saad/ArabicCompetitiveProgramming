/*
 * 298A.cpp
 *
 *  Created on: Feb 12, 2014
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

	int n;
	char arr[1001];

	cin>>n;
	cin>>arr;

	//determine fst and last positions
	int fst = 0;
	int lst = 0;

	//Find first non . character
	for(int i = 0; i < n; ++i)
	{
		if(arr[i] != '.')
		{
			fst = i;
			break;
		}
	}

	//Find last non . character
	for(int i = n-1; i >= 0; --i)
	{
		if(arr[i] != '.')
		{
			lst = i;
			break;
		}
	}

	//we have 3 cases: RRRRRRRRRR, LLLLLLLLLL, RRRRRRRRLLLLLL

	if(arr[fst] == 'R' && arr[lst] == 'R')
		cout<<fst+1<<" "<<lst+1+1<<"\n";	//+1 for 1 based. Another +1 for position shifting

	else if(arr[fst] == 'L' && arr[lst] == 'L')
		cout<<lst+1<<" "<<fst-1+1<<"\n";

	else if(arr[fst] == 'R' && arr[lst] == 'L')
	{
		//Find the position of flip from R to L
		for(int i = fst; i < n; ++i)
		{
			lst = i;

			if(arr[i] == 'L')
				break;
		}

		cout<<fst+1<<" "<<lst-1+1<<"\n";
	}

	// Another implementation: use string str with methods find and find_last_of

	return 0;
}
