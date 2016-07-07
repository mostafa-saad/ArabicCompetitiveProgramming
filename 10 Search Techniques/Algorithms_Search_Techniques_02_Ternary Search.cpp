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

typedef long long ll;
const ll OO = 1e8;

const double EPS = (1e-11);
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;





















// TC( 	TCCC05 Round 2  Driving and watchtower  	SRM 240 D1-2), UVA(11243, 11829, 11257), codeforces(98C, 250D)
// http://www.codechef.com/APRIL11/problems/CPOINT/
// http://www.codechef.com/ACMAMR12/problems/BALL
// http://www.codechef.com/problems/K1
// http://www.codechef.com/problems/CIELKARA/








/*
 * 1- Ternary Search is a divide and conquer search algorithm like Binary search. Divides data, and drop some parts and conquer others .
 * 2- In the given RANGE, function must be either: STRICTLY INCREASING then STRICTLY DECCREASING Or reverse
 * 3- Hence, function has only 1 mode (one min or max val)
 * 4- We target finding this mode.
 * 5- Divide space to 3 parts, target mode either in the first 2 parts or last 2 parts.
 *
 * Let a unimodal function f(x) on some interval [l; r]. Take any two points m1 and m2 in this segment: l < m1 < m2 < r. Then there are three possibilities:

 if f(m1) < f(m2), then the required maximum can not be located on the left side - [l; m1].
 It means that the maximum further makes sense to look only in the interval [m1;r]
 if f(m1) > f(m2), that the situation is similar to the previous, up to symmetry.
 Now, the required maximum can not be in the right side - [m2; r], so go to the segment [l; m2]
 if f(m1) = f(m2), then the search should be conducted in [m1; m2], but this case can be attributed to any of the PREVIOUS two (in order to simplify the code).
 */



























/*
 * A typical example will be given strictly decreasing then increasing sequence, find min value. Let's try a better example
 *
 * We are given set of integers, find a position (once real and once integer) that has minimum absolute difference summation
 *
 * Then f function is as below. For a given position, sum distances
 */









vector<int> v;
double f(double x) {	// we could implement it faster
	double dist = 0;

	rep(i, v)
		dist += abs(x - v[i]);

	return dist;
}

/*
 * How to think ternary? If it is ternary, say we search for min value, then you know we keep decreasing, then increasing starts.
 * Think in the order of x ~-> f(x) that you need to try, and have intuitive if the given function behaves as we need or not.
 *
 * An intuitive of x's typically will be sorted numbers. Say sorted numbers are 1 2 3 4 5 6 7
 *
 * Say we evaluated the value at first position, we expect sum to be so high -> 21
 * Now, think what happens when we move to right 1 step?
 *
 * We got -6 from the left 6 numbers and got +1 for right number -> 16
 *
 * So the more we move to left, we become nearer to left numbers, and further from right numbers
 *
 * F function gives: 21 16 13 12 13 16 21.
 *
 * So search seems ternable search, one more validation is required, is inc/dec strict? Homework
 *
 * Note, although 16 is duplicate, it is strict dec, then strict enc
 *
 * What if numbers are: 1 2 3 4 4 4 4 5 6 7 8
 *
 * F function is : 37 28 21 16 16 16 16 19 24 31 40
 *
 * Number 16 is repeated 4 times! So definitely this is not strict and ternary won't work!
 *
 * True, but algorithm will work if the repetition in the mode value only. Homework: Validate! Don't take every thing as fact :)
 *
 * Homework: why ternary needs f space to be strict?
 *
 * E.g. if we want to find minimum value in given list 5 1 5 5 5 5 5, answer may be 5 not 1
 */








pair<double, double> ternaryReal() {
	double left = v[0], right = v.back(); // set your range
	while (right - left > EPS) { // stop when reaching almost right = left
		double g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;

		if (f(g) < f(h)) // use > if f increase then decrease
			right = h;
		else
			left = g;
	}

	return make_pair(left, f(left));
}

// Note, many ppl prefer to work up to 200/300 iterations to avoid precision/infinite loop problems. Same as in binary search




























pair<int, int> ternaryDiscrete() {
	int left = v[0], right = v.back(); // set your range
	while (right-left > 3) { // We need 4 different positions
		int g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;

		if (f(g) < f(h)) // use > if f increase then decrease
			right = h;
		else
			left = g;
	}

	int solIdx = left, answer = f(left++);
	for (int i = left; i <= right; ++i)	// iterate on the remaining
		if(answer > f(i))
			answer = f(i), solIdx = i;

	return make_pair(solIdx, answer);
}






















/*
 * Could you guess an O(1) answer? Yes, from function nature, the mid value in the array is the answer -> f(v[sz(v)/2])
 *
 * Homework: In the given problem, will ternary find the correct answer as discrete? As value not position
 *
 * Say we have function like (X-c)^2, and want to find the min value of this function.
 * 	Thorough differentiation, we could find the answer directly.
 *
 * To sum up, some times we could find analytical and calculs solutuion. Many times, doing differentiation for f is hard!
 *
 * To sum up: do ternary if allowed, and hard to find direct solution or lazy to think :)
 */













/*
 * What if we are given set of points (x, y) and need to find point p that has minimum Manhattan distance summation?
 * 	Now problem became 2D :(
 *
 * Remember the Independence feature
 * 		Minimize Manhattan Distance = Minimize on Xs + Minimize on Ys
 *
 * 		Hence once in 1D find best x, and once find best y
 *
 * 	What if function is square of the Euclidean distance?
 *
 * 	Similarly: Sum(Pi, p) = Sum (Pi.x-p.x)^2 + Sum (Pi.y-p.y)^2		for i [1-n], and p is target point
 *
 *
 *  What if function is the Euclidean distance?!!!
 *  Now it is really a 2D problem! You can't do a split!
 *
 *  This where Nested Ternary appears. We have 2 F functions.
 *  First ternary works on X in x ranges and call FX(x)
 *
 *  FX is a nested ternary function that works on y, given x and evaluates FXY(x, y)
 *
 *  WAIT! For both functions, you must guarantee that their spaces are strict dec/enc! Homework
 *
 *  Homework: Read about Golden section search and Fibonacci search
 */















/*
 * There are little problems on ternary, and due to algorithm nature many of them in geometry, which is not easy field.
 *
 * Proving that space allows for ternary is always hard. One of interesting and popular cases when space is convex function.
 * Studying convex function and their properties let you prove/solve many ternary search problems.
 */











int main() {
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

	int n;
	cin>>n;
	lp(i, n)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}

	rep(i, v)
		cout<<f(v[i])<<" ";
	cout<<"\n";

	pair<double, double> p1 = ternaryReal();
	cout<<p1.first<<" "<<p1.second<<"\n";

	pair<int, int> p2 = ternaryDiscrete();
	cout<<p2.first<<" "<<p2.second<<"\n";

	return 0;
}



