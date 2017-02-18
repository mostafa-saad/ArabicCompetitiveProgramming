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

int calcMex(unordered_set<int> hashtable) {
  int val = 0;

  while (hashtable.find(val) != hashtable.end())
    val++;
  return (val);
}

int k;
int grundy[100];  // initialize to -1
int steps[100];

int calcGrundy3(int n) {
  if (n == 0)
    return 0;

  int &ret = grundy[n];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;
  steps[n] = 1000000;

  for (int v = 1; v <= n; v *= k) {
    int sol = calcGrundy3(n - v);
    sub_nimbers.insert(sol);

    if (sol == 0)  // then I win, let's minimize
      steps[n] = min(steps[n], steps[n - v] + v);
  }
  if (steps[n] == 1000000)
    steps[n] = 0;  // we will lose

  return ret = calcMex(sub_nimbers);
}

int solve(int s, int k) {
  int x = s % (k + 1);
  if (k % 2 == 0 && x == k)
    return k;     // value k repeats in regular way
  return x % 2;   // all other values are 0 and 1
}

/////////////////////////////////////////////////

// Solution for: Shuriken Game COJ

  int grundy2[120][120];
  int steps2[120][120];

  int calcGrundy4(int n, int last) {
    if (n == 0)
      return 0;

    int &ret = grundy2[n][last];
    if (ret != -1)
      return ret;

    unordered_set<int> sub_nimbers;
    steps2[n][last] = 1000000;

    for (int v = 1; v <= k && n - v >= 0; v++)
      if (v != last) {
        int sol = calcGrundy4(n - v, v);
        sub_nimbers.insert(sol);

        if (sol == 0)  // then I win, let's minimize
          steps2[n][last] = min(steps2[n][last], steps2[n - v][v] + v);
      }
    if (steps2[n][last] == 1000000)
      steps2[n][last] = 0;  // we will lose

    return ret = calcMex(sub_nimbers);
  }


int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif

  return 0;
}

