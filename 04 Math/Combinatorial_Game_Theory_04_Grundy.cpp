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

int grundy[100];  // initialize to -1

int calcGrundy1(int n) {
  if (n == 0)
    return 0;

  int &ret = grundy[n];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  for (int i = 1; i <= 3; i++)
    if (n >= i)
      sub_nimbers.insert(calcGrundy1(n - i));

  return ret = calcMex(sub_nimbers);
}

int calcGrundy2(int n) {
  if (n == 0)
    return 0;

  int &ret = grundy[n];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;
  int moves[3] = { 2, 3, 6 };

  for (int i = 0; i < 3; i++)
    sub_nimbers.insert(calcGrundy2(n / moves[i]));

  return ret = calcMex(sub_nimbers);
}

///////

int grundy2[120][120];

bool valid(int v) {
  return v >= 0 && v < 8;
}

int calcGrundyChess(int r, int c) {
  int &ret = grundy2[r][c];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  const int DIR = 4;
  int dr[DIR] = { 1, -1, -2, -2 };
  int dc[DIR] = { -2, -2, 1, -1 };

  for (int d = 0; d < 4; ++d) {
    if (valid(r + dr[d]) && valid(c + dc[d]))
      sub_nimbers.insert(calcGrundyChess(r + dr[d], c + dc[d]));
  }
  return ret = calcMex(sub_nimbers);
}

void chessMain() {
  clr(grundy2, -1);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cout << calcGrundyChess(i, j) << " ";
    }
    cout << "\n";
  }

  int nimXor = 0, knights;

  cin>>knights;
  for (int d = 0; d < knights; ++d) {
    int x, y;
    cin>>x>>y;
    nimXor ^= calcGrundyChess(x, y);
  }
  if(nimXor != 0)   cout<<"First win";
  else              cout<<"Second win";
}


int main() {


	chessMain();
	
  return 0;
}

