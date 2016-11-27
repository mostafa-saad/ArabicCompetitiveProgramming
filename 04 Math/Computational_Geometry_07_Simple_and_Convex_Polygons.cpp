#include <iostream>
#include <cmath>
#include <complex>
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

const double EPS = 1e-9;

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

int ccw(point a, point b, point c) {
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
    return +1;
  if (t < -EPS)
    return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
    return -1;
  if (norm(v1) < norm(v2) - EPS)
    return +1;
  return 0;
}


bool intersect(point p1, point p2, point p3, point p4) {
  // special case handling if a segment is just a point
  bool x = (p1 == p2), y = (p3==p4);
  if(x && y)  return p1 == p3;
  if(x)   return ccw(p3, p4, p1) == 0;
  if(y)   return ccw(p1, p2, p3) == 0;

  return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
      ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

////////////////////////////////////////////////////////

// assume p0 is added again to p (n+1 points)
bool isSimplePolygon(vector<point> &p) {
  for (int i = 0; i < sz(p) - 1; i++) {
    for (int j = i + 2; j < sz(p) - 1; j++)
      if (intersect(p[i], p[i + 1], p[j], p[j + 1]) && (i != 0 || j != sz(p) - 2) /* last/first edges are consecutive*/)
        return false;   //Segments must not share vertices
  }
  return true;
}

      bool isConvexPolygon(vector<point> &p) {
        // all polygon 3 consecutive points must have same sign (ccw or cw)
        p.push_back(p[0]), p.push_back(p[1]); // wrap points for simplicity

        int sign = ccw(p[0], p[1], p[2]);
        bool ok = true;
        for (int i = 1; ok && i < sz(p) - 2; i++) {
          if (ccw(p[i], p[i + 1], p[i + 2]) != sign)
            ok = false;
        }
        p.pop_back(), p.pop_back();
        return ok;
      }

      // isConcave = !isConvex
      // isConcave = 2 different signs

int main() {


  return 0;
}
