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














// subset DP. 1 2 3 4 5 6



int numList[] = {5, 2, 7, 3, 4, 6};	// solution is finally set of 0s and 1s..pick or leave.
//			     0  1  0  1  1  1

int m = 7;
// called with LIS(0, m)
int LIS(int i, int prev)
{
	if(i == m)
		return 0;

	int choice1 = LIS(i+1, prev);	// LEAVE
	int choice2 = 0;

	if(numList[prev] <= numList[i])
		choice2 = LIS(i+1, i) + 1;

	return max(choice1, choice2);
}































// W: 10, 4 , 20, 5, 7
// P: 10, 15, 3 , 1, 4

// knapsack size = 12
//	  0   1   0   0  1

const int MAX = 5;
int n = 5;
int weights[MAX] = {10, 4, 20, 5, 7};
int benfit[MAX] = {10, 15, 3, 1, 4};

// called with knapsack(0, intialWeight)
int knapsack(int i, int reminder)	// aka 0/1 knapsack
{
	if(i == n)
		return 0;

	int choice1 = knapsack(i+1, reminder);
	int choice2 = 0;

	if(reminder >= weights[i])
		choice2 = knapsack(i+1, reminder - weights[i]) + benfit[i];

	return max(choice1, choice2);
}


























string str1 = "abcdefgzh";
string str2 = "ackghefhlmn";

// abcdefgzh
// 101011001

// ackghefhlmn
// 11000111000

// called with LCS(0, 0)
int LCS(int i, int j)
{
	if(i == sz(str1) || j == sz(str2))
		return 0;

	if(str1[i] == str2[j])
		return 1 + LCS(i+1, j+1);

	int choice1 = LCS(i+1, j);
	int choice2 = LCS(i, j+1);

	return max(choice1, choice2);
}




























int main()
{

	cout<<LCS(0, 0);

	return 0;
}
