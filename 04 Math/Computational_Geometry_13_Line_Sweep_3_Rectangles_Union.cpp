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

// Original code source: https://olympiad.cs.uct.ac.za/presentations/camp1_2009/linesweep_handout.pdf

  struct event {
    int ind, type;
    event() {}
    event(int ind, int type) : ind(ind), type(type) {}
  };
  struct point {  int x, y;   };

  const int RECT_MAX = 10000 + 9;
  const int ENTRY = 0, EXIT = 1;
  point rects[RECT_MAX][2];
  bool inActiveSet[RECT_MAX];
  event events_v[2 * RECT_MAX], events_h[2 * RECT_MAX];

  bool cmpX(event a, event b) {
    return rects[a.ind][a.type].x < rects[b.ind][b.type].x;
  }
  bool cmpY(event a, event b) {
    return rects[a.ind][a.type].y < rects[b.ind][b.type].y;
  }



int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif

  long long area = 0;
  int n = 0, eventsCnt = 0;  // # rectangles, edges

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {  // assume rectangle 2 points are ordered
    scanf("%d %d %d %d", &rects[i][0].x, &rects[i][0].y, &rects[i][1].x, &rects[i][1].y);
    events_v[eventsCnt] = event(i, ENTRY), events_v[eventsCnt + 1] = event(i, EXIT);
    events_h[eventsCnt] = event(i, ENTRY), events_h[eventsCnt + 1] = event(i, EXIT);
    eventsCnt += 2;
  }
  sort(events_v, events_v + eventsCnt, cmpX);
  sort(events_h, events_h + eventsCnt, cmpY);

  inActiveSet[events_v[0].ind] = 1;
  for (int v = 1; v < eventsCnt; ++v) {  // Vertical sweep
    event c = events_v[v], p = events_v[v - 1];
    int cnt = 0, first_rect, delta_x, delta_y;

    if ((delta_x = rects[c.ind][c.type].x - rects[p.ind][p.type].x) == 0)
      continue;

    for (int h = 0; h < eventsCnt; ++h)
      if (inActiveSet[events_h[h].ind]) {  // Horizontal sweep
        if (events_h[h].type == ENTRY) {
          if (cnt++ == 0)
            first_rect = h;
        } else if (--cnt == 0) {
          delta_y = rects[events_h[h].ind][EXIT].y - rects[events_h[first_rect].ind][ENTRY].y;
          area += delta_x * delta_y;
        }
      }
    inActiveSet[c.ind] = (c.type == ENTRY);
  }



  printf("%lld\n", area);
  return 0;
}

