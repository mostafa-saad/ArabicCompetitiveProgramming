  /*
   *
   *  Created on: Oct 29, 2016
   *      Author: mostafa saad
   *
   *
   *  tested on timus_1469_no_smoking
   *      http://acm.timus.ru/problem.aspx?space=1&num=1469
   */

  #include <iostream>
  #include <cmath>
  #include <complex>
  #include <cassert>
  #include <bits/stdc++.h>
  using namespace std;

  const double PI = acos(-1.0);
  const double EPS = 1e-8;

  int dcmp(double a, double b) {
    return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
  }

  typedef complex<int> point;

  #define X real()
  #define Y imag()
  #define angle(a)                (atan2((a).imag(), (a).real()))
  #define vec(a,b)                ((b)-(a))
  #define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
  #define dp(a,b)                 ( (conj(a)*(b)).real() )  // a*b cos(T), if zero -> prep
  #define cp(a,b)                 ( (conj(a)*(b)).imag() )  // a*b sin(T), if zero -> parllel
  #define length(a)               (hypot((a).imag(), (a).real()))
  #define normalize(a)            (a)/length(a)
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
    bool x = (p1 == p2), y = (p3 == p4);
    if (x && y)
      return p1 == p3;
    if (x)
      return ccw(p3, p4, p1) == 0;
    if (y)
      return ccw(p1, p2, p3) == 0;

    return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
  }

  ////////////////////////////////////////////////////////////

  bool operator <(point &a, point &b) {
    if (dcmp(a.X, b.X) != 0)
      return dcmp(a.X, b.X) < 0;
    return dcmp(a.Y, b.Y) < 0;
  }

  struct segment {
    point p, q;
    int seg_idx;

    segment() {seg_idx = -1;}
    segment(point p_, point q_, int seg_idx_) {
      if (q_ < p_)
        swap(p_, q_);
      p = p_, q = q_, seg_idx = seg_idx_;
    }

    double CY(int x) const {
      if (dcmp(p.X, q.X) == 0)
        return p.Y; // horizontal

      double t = 1.0 * (x - p.X)/(q.X - p.X);
      return p.Y + (q.Y - p.Y)*t;
    }
    // operator< is very tricky and can cause 100 WAs.
    bool operator<(const segment& rhs) const {
      if(same(p, rhs.p) && same(q, rhs.q))
        return false;

      int maxX = max(p.X, rhs.p.X);
      int yc = dcmp(CY(maxX), rhs.CY(maxX));

      if (yc == 0) // critical condition
        return seg_idx < rhs.seg_idx;
      return yc < 0;
    }
  };

  ////////////////////////////////////////////////////////////

  int ENTRY = +1, EXIT = -1;          // entry types
  const int MAX_SEGMENTS = 50000 + 9;
  const int MAX_EVENTS = MAX_SEGMENTS * 2;

  struct event {
    point p;
    int type, seg_idx;
    // smaller X first. If tie: ENTRY event first. Last on smaller Y
    bool operator <(const event & rhs) const {
      if (dcmp(p.X, rhs.p.X) != 0)
        return dcmp(p.X, rhs.p.X) < 0;
      if (type != rhs.type)
        return type > rhs.type;
      return dcmp(p.Y, rhs.p.Y) < 0;
    }
  };

  int n;
  segment segments[MAX_SEGMENTS];
  event events[MAX_EVENTS];
  set<segment> sweepSet;
  typedef set<segment>::iterator ITER;

  ////////////////////////////////////////////////////////////

  bool intersectSeg(ITER seg1Iter, ITER seg2Iter) {
    if (seg1Iter == sweepSet.end() || seg2Iter == sweepSet.end())
      return false;
    return intersect(seg1Iter->p, seg1Iter->q, seg2Iter->p, seg2Iter->q);
  }

  ITER after(ITER cur) {
    return cur == sweepSet.end() ? sweepSet.end() : ++cur;
  }

  ITER before(ITER cur) {
    return cur == sweepSet.begin() ? sweepSet.end() : --cur;
  }

  void FoundIntersection(int i, int j) {
    printf("%d %d\n", i + 1, j + 1);
  }

  void bentleyOttmann_lineSweep() {   // O( (k+n) logn )
    // Prepare events
    lp(i, n)
    {
      events[2*i] = {segments[i].p, ENTRY, i};
      events[2*i+1] = {segments[i].q, EXIT, i};
    }
    sort(events, events+2*n);

    lp(i, 2*n) {
      if (events[i].type == ENTRY) {
        auto status = sweepSet.insert(segments[events[i].seg_idx]);
        ITER cur = status.first, below = before(cur), above = after(cur);

        if(!status.second) {
          FoundIntersection(cur->seg_idx, events[i].seg_idx); // Duplicate
        } else {
          if(intersectSeg(cur, above))
            FoundIntersection(cur->seg_idx, above->seg_idx);
          if(intersectSeg(cur, below))
            FoundIntersection(cur->seg_idx, below->seg_idx);
        }
      } else {
        ITER cur = sweepSet.find(segments[events[i].seg_idx]);

        if(cur == sweepSet.end())
          continue; // e.g. Duplicate

        ITER below = before(cur), above = after(cur);

        if(intersectSeg(above, below))
          FoundIntersection(above->seg_idx, below->seg_idx);
        sweepSet.erase(cur);
      }
    }
  }

  ////////////////////////////////////////////////////////////

  int main() {
  #ifndef ONLINE_JUDGE
    freopen("test.txt", "rt", stdin);
  #endif

    int x, y;

    cin >> n;
    lp(i, n)
    {
      cin >> x >> y;      point p1 = point(x, y);
      cin >> x >> y;      point p2 = point(x, y);

      segments[i] = segment(p1, p2, i);
    }
    bentleyOttmann_lineSweep();

    return 0;
  }
