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

int f(int n) {return 0;}
bool can(int m) {return 0;}

/*


Content:
- How do you find page number?
- Recursive and Iterative Code
- When we know it is BS?
- Finding first and last occuerance
- BS over real numbers

UVA(10077, 10611), TopCoder(), SRM258(AutoLoan), SRM230(SortEstimate), SRM277(UnionOfIntervals), SRM189(Mortgage), SRM169(FairWorkload), SRM261(HairCuts), SRM270(PackingShapes), SRM235(RemoteRover), SRM210(NegativePhotoresist), SRM204(WorldPeace), SRM278(UnitsMoving), SRM236(Parking), SRM190(SquareFree), SRM147(Flags), CodeForces(166A, 161A, 195A, 279B, 271B), SPOJ(AGGRCOW, BOOKS1, ICPCS, MSE07E)

 */

// O(log N)

// STL implements binary search in algorithms lower_bound, upper_bound, binary_search and equal_range

// Read http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binarySearch

/*
 * Binary Search works only if space is a guide. That is from any position you know to which direction to go?
 * 	In more theorical words: binary search can be used if and only if for all x in S, p(x) implies p(y) for all y > x
 *
 * Typically works in increasing or decreasing sequence. Some times works in bitonic sequence (increase then decrease or reverse)
 *
 *
 * 1 7 9 15 6 4 2
 */

/*
 * 1- Instead of an index in array, we could have function F(int idx) that calculate some value.
 *
 * 		E.g. we have an increasing function F (e.g. Fibonacci 1 1 2 3 5 8 13 ...) what is index of 21?
 *
 *
 * 	2- In many problems, function F is boolean function could(int val).
 *
 * 		E.g. If we are given # of sandwiches to eat during trip. Using them you could reach your destination or die from starving as food ended.
 * 			What is MIN # of sandwiches to finish trip and still alive?
 *
 * 		in this case space is like  0 0 0 0 0 0 1 1 1 1 1
 *
 * 			That is e.g. given up to 6 sandwiches u die, but more than that you could pass.
 *
 * 		Sometimes space is reverse 1 1 1 1 1 0 0 0 0 0 0
 *
 * 		Sometimes you are asked for first 1 (or) zero and some times you are asked for the last.
 *
 * 		For more understanding for first and last: Imagine array: 1 3 4 5 9 9 9 12 15 ...
 * 			Find 1st idx of 9? Find last idx of 9?
 * 			So it is not just about finding, but which position? any? first? last?
 *
 * 		Final note: remember (e.g. in 0 0 0 0 0 0 1 1 1 1 1) the last zero followed by the first one. So you could be asked to last, and solve it usign first.
 */


















// start + (end-start)/2 = (start + end) / 2

int BSfindFirst(int start, int end, int val) {
	while(start < end) {
		int mid = start + (end-start)/2;
		if(f(mid) < val)		start= mid+1;
		else if(f(mid) > val)	end  = mid-1;
		else					end  = mid;
	}
	return start;
}

int BSfindLast(int start, int end, int val) {
	while(start < end) {
		int mid = start + (end-start)/2;
		if(f(mid) < val)		start= mid+1;
		else if(f(mid) > val)	end  = mid-1;
		else					start= mid;
	}
	return start;
}
















// A typical scenario is infinite loop when a start or end = mid. To fix that
// check to use: mid = start + (end-start)/2;	OR		 mid = start + (end-start+1)/2;
// check any 2 consecutive numbers: E.g. 1, 2


// If you forgot this trick, just work till range be > small number (e.g. 5) and then move the remain steps sequentially.


















// One of great WAs sources is value of EPS. Make sure you achieve required precision

double BS_double(double start, double end, double val) {
	while(fabs(end - start) > EPS) {	// iterate 100-500 iteration
		double mid = start + (end-start)/2;
		if(f(mid) < val)	start= mid;
		else 				end  = mid;
	}
	return start;
}


double binary(double start, double end)
{
	lp(i, 100) {	// loop as much as u want
	    double mid = (start+end)/2;
	    if( can(mid) )
	    	end = mid;
	    else
	    	start = mid;
	}

	if( can(end) )
		return start;

	return -1;	// failed
}






















int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	return 0;
}
