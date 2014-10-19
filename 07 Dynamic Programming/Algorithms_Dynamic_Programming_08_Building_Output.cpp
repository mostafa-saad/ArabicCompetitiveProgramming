/*
 * 526.cpp
 *
 *  Created on: May 15, 2013
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
string str1, str2;

int mem[MAX][MAX];

int editDistance(int i, int j)
{
	if(i == sz(str1))
		return sz(str2) - j;	// add from str2

	if(j == sz(str2))
		return sz(str1) - i;	// delete them

	int &ret = mem[i][j];

	if(ret != -1)
		return ret;

	if(str1[i] == str2[j])
		return ret = editDistance(i+1, j+1);

	int choice1 = 1 + editDistance(i, j+1);		// add str2[j] before str1[i]
	int choice2 = 1 + editDistance(i+1, j);		// remove str1[i]
	int choice3 = 1 + editDistance(i+1, j+1);	// replace str1[i] = str2[j];

	return ret = min(choice1, min(choice2, choice3));
}



















int idx = 0;
int idxShift;
void traceOperations(int i, int j)	// note that we call function, NOT call mem array.
{
	if(i == sz(str1))
	{
		int toAdd =  sz(str2) - j;
		lp(k, toAdd)
			cout<<++idx<<" Insert "<<i+k+1+idxShift<<","<<str2[j+k]<<"\n";
		idxShift += toAdd;
		return;
	}

	if(j == sz(str2))
	{
		int toDelete =  sz(str1) - i;
		lp(k, toDelete)
		{
			cout<<++idx<<" Delete "<<i+k+1+idxShift<<"\n";
			--idxShift;
		}

		return;
	}

	if(str1[i] == str2[j]) {
		traceOperations(i+1, j+1);
		return;
	}

	int choice1 = 1 + editDistance(i, j+1);		// add str2[j] before str1[i]
	int choice2 = 1 + editDistance(i+1, j);		// remove str1[i]
	int choice3 = 1 + editDistance(i+1, j+1);	// replace str1[i] = str2[j];

	// Let's see which choice was the correct one.
	int optimal = editDistance(i, j);

	if(choice1 == optimal) {
		cout<<++idx<<" Insert "<<i+1+idxShift<<","<<str2[j]<<"\n";
		++idxShift;
		traceOperations(i, j+1);
	} else if(choice2 == optimal) {
		cout<<++idx<<" Delete "<<i+1+idxShift<<"\n";
		--idxShift;
		traceOperations(i+1, j);
	} else {
		cout<<++idx<<" Replace "<<i+1+idxShift<<","<<str2[j]<<"\n";
		traceOperations(i+1, j+1);
	}
}










/*
abcdefgh
defgh

3
1 Delete 1
2 Delete 1
3 Delete 1
 */

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif


	string line = "";
	while(getline(cin, str1) && getline(cin, str2))
	{
		line = "\n";

		clr(mem, -1);
		cout<<editDistance(0, 0)<<"\n";
		
		idxShift = idx = 0;
		traceOperations(0, 0);
	}

	return 0;
}
