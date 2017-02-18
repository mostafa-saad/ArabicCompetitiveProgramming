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

int remotnessMem[120][120];
int suspenseMem[120][120];

bool valid(int v) {
  return v >= 0 && v < 8;
}

const int DIR = 4;
int dr[DIR] = { 1, -1, -2, -2 };
int dc[DIR] = { -2, -2, 1, -1 };
const int OO = 1000000;

int calcRemoteness(int r, int c) {
  int &ret = remotnessMem[r][c];
  if (ret != -1)
    return ret;

  int leastEven = OO, largestOdd = -OO;

  for (int d = 0; d < 4; ++d) {
    if (valid(r + dr[d]) && valid(c + dc[d])) {
      int remotness = calcRemoteness(r + dr[d], c + dc[d]);
      if (remotness % 2 == 0)
        leastEven = min(leastEven, remotness);
      else
        largestOdd = max(largestOdd, remotness);
    }
  }
  ret = 0;
  if (leastEven != OO)
    ret = 1 + leastEven;
  else if (largestOdd != -OO)
    ret = 1 + largestOdd;
  return ret;
}

void chessRemotenessMain() {
  clr(remotnessMem, -1);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cout << calcRemoteness(i, j) << " ";
    }
    cout << "\n";
  }

  int minVal = 1000000, knights;

  cin >> knights;
  for (int d = 0; d < knights; ++d) {
    int x, y;
    cin >> x >> y;
    minVal = min(minVal, calcRemoteness(x, y));
  }
  if (minVal % 2 != 0)
    cout << "First win";
  else
    cout << "Second win";
}

int calcSuspense(int r, int c) {
  int &ret = suspenseMem[r][c];
  if (ret != -1)
    return ret;

  int largestEven = -OO, leastOdd = OO;

  for (int d = 0; d < 4; ++d) {
    if (valid(r + dr[d]) && valid(c + dc[d])) {
      int remotness = calcSuspense(r + dr[d], c + dc[d]);
      if (remotness % 2 == 0)
        largestEven = max(largestEven, remotness);
      else
        leastOdd = min(leastOdd, remotness);
    }
  }
  ret = 0;
  if (largestEven != -OO)
    ret = 1 + largestEven;
  else if (leastOdd != OO)
    ret = 1 + leastOdd;
  return ret;
}

void chessSuspenseMain() {
  clr(remotnessMem, -1);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cout << calcRemoteness(i, j) << " ";
    }
    cout << "\n";
  }

  int maxVal = -1000000, knights;

  cin >> knights;
  for (int d = 0; d < knights; ++d) {
    int x, y;
    cin >> x >> y;
    maxVal = max(maxVal, calcRemoteness(x, y));
  }
  if (maxVal % 2 != 0)
    cout << "First win";
  else
    cout << "Second win";
}

int calcRemotenessMisere(int r, int c) {
  int &ret = remotnessMem[r][c];
  if (ret != -1)
    return ret;

  int leastOdd = OO, largestEven = -OO;

  for (int d = 0; d < 4; ++d) {
    if (valid(r + dr[d]) && valid(c + dc[d])) {
      int remotness = calcRemotenessMisere(r + dr[d], c + dc[d]);
      if (remotness % 2 != 0)  // 1st change in calcSuspense
        leastOdd = min(leastOdd, remotness);
      else
        largestEven = max(largestEven, remotness);
    }
  }
  ret = 0;
  if (leastOdd != OO)    // 2nd change in calcSuspense
    ret = 1 + leastOdd;
  else if (largestEven != -OO)
    ret = 1 + largestEven;
  return ret;
}

int main() {

  chessSuspenseMain();

  return 0;
}

