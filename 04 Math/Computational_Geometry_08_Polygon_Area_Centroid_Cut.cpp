#include <iostream>
#include <cmath>
#include <complex>
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

const double EPS = 1e-8;

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
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

point reflect(point p, point p0, point p1) {
  point z = p - p0, w = p1 - p0;
  return conj(z / w) * w + p0;  // Refelect point p1 around p0p1
}

#define all(v)      ((v).begin()), ((v).end())
#define sz(v)     ((int)((v).size()))
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)


double polygonArea(vector<point>& points) {
    long double a = 0;
    rep(i, points)  a += cp(points[i], points[ (i+1) % sz(points) ]);
    return fabs(a/2.0);    // If area > 0 then points ordered ccw
}

point polygonCenteriod(vector<point> points) {
  double x = 0, y = 0, a = 0, c;

  for(int i = 0; i < points.size(): ++i)
  {
	int j = (i + 1) % sz(points);
	c = cp(points[i], points[j]), a += c;
	x += (points[i].X + points[j].X) * c;
	y += (points[i].Y + points[j].Y) * c;
  }
  if (dcmp(a, 0) == 0)
	return (points[0] + points.back()) * 0.5;   // Line
  a /= 2, x /= 6 * a, y /= 6 * a;
  
  // Fix values in case
  if (dcmp(x, 0) == 0)	x = 0;
  if (dcmp(y, 0) == 0)	y = 0;

  return point(x, y);
}


// P need to be counterclockwise convex polygon
pair<vector<point>, vector<point> > polygonCut(vector<point> &p, 
	point A, point B) {
		
  vector<point> left, right;
  point intersect;

  for (int i = 0; i < sz(p); ++i) {
	point cur = p[i], nxt = p[(i + 1) % sz(p)];

	if ( cp(B-A, cur-A) >= 0)
	  right.push_back(cur);

	//NOTE adust intersectSegments should handled AB as line
	if (intersectSegments(A, B, cur, nxt, intersect)) {  
	  right.push_back(intersect);
	  left.push_back(intersect);
	}

	if ( cp(B-A, cur-A) <= 0)
	  left.push_back(cur);
  }
  return make_pair(left, right);
}

int main() {


  return 0;
}
