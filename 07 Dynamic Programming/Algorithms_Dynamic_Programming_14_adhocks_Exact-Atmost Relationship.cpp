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

int n, rem;
vector<int> mn, mx;
int mem[1000][1000];










/*
 * Exact & atmost relationship
 * 
 * E.g. Exact could be, How many ways to pick k balls out of n balls. Then Exact(K) = N choose K
 * 		Atmost could be, How many ways to pick maximum k balls out of n balls. Then Atmost(K) = SUM Exact(i) where i = [0-k]
 * 		
 * 		
 * 	Why important? Cause we could get one from another. Sometimes doing exact is easier/more efficint...some times reverse is true.
 * 	
 * 	Exact(k) = Atmost(k) - Atmost(k-1)
 * 	Atmost(k) = SUM Exact(i) where i = [0-k]
 * 	
 * 	SUM Exact(i) where i = [start-end] =  Atmost(end) - Atmost(start-1)
 * 	
 * 	Notice how having atmost could answer us exact, and range sums in O(1)! 
 */

































int Exact(int i, int rem)
{
	if(rem < 0)	return 0;

	if(i == n)
		return rem == 0;

	int ret = Exact(i, rem-1) + Exact(i+1, rem);

	return ret;
}















int AtMost(int i, int rem)
{
	if(rem < 0)	return 0;

	if(i == n)
		return 1;

	int ret = AtMost(i, rem-1) + AtMost(i+1, rem);

	return ret;
}


























int ExactStdeuntRange(int i, int rem)
{
	if(i == n)
		return rem == 0;

	int ret = 0;
	lpi(v, mn[i], min(rem, mx[i])+1)
		ret += ExactStdeuntRange(i+1, rem - v);

	return ret;
}

int AtMostStdeuntRange(int i, int rem)
{
	if(rem < 0)
		return 0;

	if(i == n)
		return 1;

	int ret = AtMostStdeuntRange(i, rem-1) + AtMostStdeuntRange(i+1, rem-mn[i]) - AtMostStdeuntRange(i+1, rem - mx[i] -1);

	return ret;
}





















int ExactStdeuntRangeDP1(int money)
{
	clr(mem, 0);

	mem[0][0] = 1;

	for(int i = 1 ; i <= n; i++)
		for(int j = mn[i-1] ; j <= money; j++)
			// analyze ur optimal substructure for a systematic behavior or any thing minimize order
			for(int k = mn[i-1]; k <= min(mx[i-1], j); k++)		
					mem[i][j] += mem[i - 1][j - k];
	return mem[n][money];
}




















int ExactStdeuntRangeDP2(int money)
{
	clr(mem, 0);

	mem[0][0] = 1;

	for(int i = 1 ; i <= n; i++)
	{
		for(int j = 1 ; j <= money; j++)	// cache table preprocessing
			mem[i-1][j] += mem[i-1][j-1];

		for(int j = mn[i-1] ; j <= money; j++)
		{
			int p = j - min(mx[i-1], j) -1;
			mem[i][j] = mem[i-1][ j-mn[i-1] ] - (p == -1 ? 0 : mem[i-1][p]);
		}
	}

	return mem[n][money];
}





















int d1, d2;
int cntWays(int i, int x, int y)	// cache table manipulation trick: From O(n^5) -> O(n^3)
{
	// some base case

	int ret = 0;

	for(int x1 = x-d1; x1 <= x+d1; ++x1)
		for(int y1 = y-d2; y1 <= y+d2; ++y1)
			ret += cntWays(i+1, x1, y1);

	return ret;
}


int cntWays()
{
	// 1- base case intialization

	// 2- lp i = N-1 to 0
		// 3- N^2 -> cache table accumulation
		// 4- N^2 -> Calculate new cache table
}

















int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	cin>>n>>rem;

	mn = vector<int>(n);
	mx = vector<int>(n);

	lp(i, n)
		cin>>mn[i]>>mx[i];

//	cout<<ExactStdeuntRange(0, rem)<<"\n";
//	cout<<AtMostStdeuntRange(0, rem) - AtMostStdeuntRange(0, rem-1)<<"\n";
	cout<<ExactStdeuntRangeDP1(rem)<<"\n";
	cout<<ExactStdeuntRangeDP2(rem)<<"\n";


	return 0;
}
