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

void solve_nim(vector<int> heap) {
  int xorsum = 0;
  for (int i = 0; i < (int) heap.size(); ++i)
    xorsum ^= heap[i];

  if (xorsum != 0) {
    cout << "First win: ";

    for (int i = 0; i < (int) heap.size(); ++i) {
      if (heap[i] > (heap[i] ^ xorsum)) {
        cout << "First Move " << (heap[i] - (heap[i] ^ xorsum)) << " stones from " << i << " heap\n";
        break;
      }
    }
  } else
    cout << "Second win\n";
}

bool misereNim(vector<int> &piles) {
  int isSpecial = 1, xorVal = 0;

  for (int i = 0; i < piles.size(); ++i) {
    xorVal ^= piles[i];
    isSpecial &= (piles[i] <= 1);
  }
  if (isSpecial)
    return xorVal == 0;
  return xorVal != 0;  // normal nim handling
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif


  return 0;
}

