/*
 *
 *  Created on: Oct 29, 2016
 *      Author: mostafa saad
 *
 */

#include <iostream>
#include <cmath>
#include <complex>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define sz(v)       ((int)((v).size()))
#define clr(v, d)     memset(v, d, sizeof(v))
#define repi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define repa(v)       repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)     repi(i, 0, sz(v))
#define lp(i, cnt)      repi(i, 0, cnt)
#define lpi(i, s, cnt)    repi(i, s, cnt)
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
#define pb          push_back
#define MP          make_pair

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef long double ld;

const double OO = 1e8;  //Small -> WRONG, Large -> OVERFLOW

const double PI = acos(-1.0);
const double EPS = (1e-8);

int dcmp(double x, double y) {
  return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

typedef complex<double> point;

#define X real()
#define Y imag()
#define vec(a,b)                ((b)-(a))
#define length(a)               (hypot((a).imag(), (a).real()))

struct cmpX {
  bool operator()(const point &a, const point &b) {
    if (dcmp(a.X, b.X) != 0)
      return dcmp(a.X, b.X) < 0;
    return dcmp(a.Y, b.Y) < 0;
  }
};

struct cmpY {
  bool operator()(const point &a, const point &b) {
    if (dcmp(a.Y, b.Y) != 0)
      return dcmp(a.Y, b.Y) < 0;
    return dcmp(a.X, b.X) < 0;
  }
};

double closestPair1(vector<point> &eventPts) {
  double d = OO;
  multiset<point, cmpY> activeWindow;
  sort(eventPts.begin(), eventPts.end(), cmpX());

  int left = 0;
  for (int right = 0; right < (int) eventPts.size(); ++right) {
    while (left < right && eventPts[right].X - eventPts[left].X > d)
      activeWindow.erase(activeWindow.find(eventPts[left++]));
    auto asIt = activeWindow.lower_bound(point(-OO, eventPts[right].Y - d));
    auto aeIt = activeWindow.upper_bound(point(-OO, eventPts[right].Y + d));
    for (; asIt != aeIt; asIt++)
      d = min(d, length(eventPts[right] - *asIt));
    activeWindow.insert(eventPts[right]);
  }
  return d;
}

int main1() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif

  int n;
  while (cin >> n && n) {
    vector<point> eventPts(n);

    for (int i = 0; i < n; ++i) {
      double x, y;
      cin >> x >> y;
      eventPts[i] = point(x, y);
    }

    double d = closestPair1(eventPts);
  }
  return 0;
}




#define foreach(a,s) for(auto a=(s).begin();a!=(s).end();a++)

double closestPair2(map<double, multiset<double> > & pointsMap) {
  double d = OO;
  foreach(xsIt, pointsMap) foreach(ymIt, xsIt->second) // sweep on each point p
    {
      double x = xsIt->first, y = *ymIt;
      // Iterate on rectangle dx2d (max 6 points)
      // iterate on active set - X dimension (distance d)
      auto xeIt = pointsMap.upper_bound(x + d);
      for (auto xIt = xsIt; xIt != xeIt; xIt++) {
        double x2 = xIt->first;
        // iterate on active set - Y dimension (distance 2d)
        auto ysIt = xIt->second.lower_bound(y - d);
        auto yeIt = xIt->second.upper_bound(y + d);
        for (; ysIt != yeIt; ysIt++) {
          if (xsIt != xIt|| ymIt != ysIt)  // if NOT original (x,y)
            d = min(d, max( abs(x-x2), abs(y-*ysIt)));
        }
      }
    }
  return d;
}



int main()
{
#ifndef ONLINE_JUDGE
  freopen("c.in", "rt", stdin);
#endif

  int n;
  while(cin>>n && n)
  {
    map<double, multiset<double> > mp;

    lp(i, n) {
      double x, y;
      cin>>x>>y;
      mp[x].insert(y);
    }

    double min = closestPair2(mp);
  }
  return 0;
}
