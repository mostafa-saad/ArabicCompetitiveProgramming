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

const double GOLDEN_RATIO = (1 + sqrt(5.0)) / 2;

pair<int, int> getKthWythoffLosingPos(int k) {
  int a = k * GOLDEN_RATIO;
  int b = k * GOLDEN_RATIO * GOLDEN_RATIO;

  // important relationship: then k = b-a
  assert(b == a + k);
  return make_pair(a, b);
}

bool isWythoffLosingPosition(int a, int b) {
  if (a > b)
    swap(a, b);
  int k = b - a;
  return a == getKthWythoffLosingPos(k).first;
}

void generateWythoff() {
  for (int i = 0; i < 20; ++i)
    cout << getKthWythoffLosingPos(i).first << " ";
  cout << "\n";

  for (int i = 0; i < 20; ++i)
    cout << getKthWythoffLosingPos(i).second << " ";
  cout << "\n";

  for (int i = 0; i < 20; ++i)
    assert(isWythoffLosingPosition(getKthWythoffLosingPos(i).first, getKthWythoffLosingPos(i).second));
}

int main() {

  generateWythoff();

  return 0;
}

