// Another buggy code by mostafa_saad
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <complex>
#include <stack>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm> 
using namespace std;

#define all(v)     ((v).begin()), ((v).end())
#define sz(v)      ((int)((v).size()))
#define clr(v, d)     memset(v, d, sizeof(v))
#define repa(v)   for(int i=0;i<(sz(v));++i) for(int j=0;j<(sz(v[i]));++j)
#define rep(i, v)      for(int i=0;i<(sz(v));++i)
#define lp(i, cnt)     for(int i=0;i<(cnt);++i)
#define lpi(i, s, cnt) for(int i=(s);i<(cnt);++i)
#define P(x)     cout<<#x<<" = { "<<x<<" }\n"
#define MP make_pair

typedef long long ll;
const int OO = (int)1e8;	// Note: Small->WRONG, Large->OVERFLOW

const double PI  = acos(-1.0);

const double EPS = (1e-8);	// use lower carefully, e.g. for binary search

int dcmp(double a, double b) {	return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1;	}

typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define polar(r,ang)            ((r)*exp(point(0,ang))) 
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)

point reflect(point p, point p0, point p1) {
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}


bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a-b), ac = length(a-c), cb = length(b-c);
	return dcmp(acb-(ac+cb), 0) == 0;
}

// Accurate and efficient
int isInsidePoly(vector<point> p, point p0) {
  int wn = 0;  // the winding number counter

  for (int i = 0; i < sz(p); i++) {
	point cur = p[i], nxt = p[(i + 1) % sz(p)];
	if (isPointOnSegment(cur, nxt, p0))
	  return true;
	if (cur.Y <= p0.Y) {    // Upward edge
	  if (nxt.Y > p0.Y && cp(nxt-cur, p0-cur) > EPS)
		++wn;
	} else {                // Downward edge
	  if (nxt.Y <= p0.Y && cp(nxt-cur, p0-cur) < -EPS)
		--wn;
	}
  }
  return wn != 0;
}

// Don't use. 
// Easy idea, multiple precision concerns
// Called: Angles Summation Test
bool isInsidePoly(vector<point> &p, point pt) {
  double anglesSum = 0;

  p.push_back(p[0]);
  for (int i = 0; i < sz(p) - 1; i++) {
    if (ccw(p[i], p[i + 1], pt) == 0) { // is pt on segment pi-pj?
      p.pop_back();
      return true;
    }
    anglesSum += angleO(p[i], pt, p[i + 1]) *
        ccw(pt, p[i], p[i + 1]); // angle pt-pi-pj is ccw?
  }
  p.pop_back();
  // Answer is either 0 (outside) or 2PI (inside)
  // return fabs(fabs(anglesSum) - 2 * PI) < EPS;
  return fabs(anglesSum) > PI;	// let's avoid EPS comparison :)
}
