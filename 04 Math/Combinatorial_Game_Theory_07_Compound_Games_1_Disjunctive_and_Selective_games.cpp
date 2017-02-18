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

int wNumbers[120][120];

bool valid(int v) {
  return v >= 0 && v < 8;
}

const int DIR = 4;
int dr[DIR] = { 1, -1, -2, -2 };
int dc[DIR] = { -2, -2, 1, -1 };

const int SL = 100000000;
const int SW = SL + 1;

int calcWNumbersChess(int r, int c) {
  int &ret = wNumbers[r][c];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  int total_moves = 0;
  for (int d = 0; d < 4; ++d) {
    int nr = r + dr[d], nc = c + dc[d];
    if (valid(nr) && valid(nc)) {
      int val = calcWNumbersChess(nr, nc);
      if (val == SL)
        return ret = SW;  // optimization
      if (val != SW)
        sub_nimbers.insert(val);
      ++total_moves;
    }
  }
  if (total_moves == 0)
    return ret = SL;
  return ret = calcMex(sub_nimbers);
}

void WNumbersChessMain() {
  clr(wNumbers, -1);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      int val = calcWNumbersChess(i, j);

      cout << setw(2);
      if (val == SL)
        cout << "SL ";
      else if (val == SW)
        cout << "SW ";
      else
        cout << val << " ";
    }
    cout << "\n";
  }

  int nimXor = 0, knights;
  bool anySuperLose = false, anySuperWin = false;

  cin >> knights;
  for (int d = 0; d < knights; ++d) {
    int x, y;
    cin >> x >> y;
    int val = calcWNumbersChess(x, y);

    if (val == SL) {
      anySuperLose = true;
      break;  // optmization
    } else if (val == SW)
      anySuperWin = true;
    else
      nimXor ^= val;
  }
  if (anySuperLose)
    cout << "Second win*";
  else if (anySuperWin)
    cout << "First win*";
  else if (nimXor != 0)
    cout << "First win";
  else
    cout << "Second win";
}

/////////////////////////////////////////////////

  int calcWNumbersChessMisere(int r, int c) {
    int &ret = wNumbers[r][c];
    if (ret != -1)
      return ret;

    unordered_set<int> sub_nimbers;

    int total_moves = 0;
    for (int d = 0; d < 4; ++d) {
      int nr = r + dr[d], nc = c + dc[d];
      if (valid(nr) && valid(nc)) {
        int val = calcWNumbersChessMisere(nr, nc);
        if (val != SW)
          sub_nimbers.insert(val);
        ++total_moves;
      }
    }
    if (total_moves == 0)
      return ret = SW;
    return ret = calcMex(sub_nimbers);
  }

  void WNumbersChessMisereMain() {
    clr(wNumbers, -1);

    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        int val = calcWNumbersChessMisere(i, j);

        cout << setw(2);
        if (val == SW)
          cout << "SW ";
        else
          cout << val << " ";
      }
      cout << "\n";
    }

    int nimXor = 0, knights;
    bool anySuperWin = false;

    cin >> knights;
    for (int d = 0; d < knights; ++d) {
      int x, y;
      cin >> x >> y;
      int val = calcWNumbersChessMisere(x, y);

      if (val == SW)
        anySuperWin = true;
      else
        nimXor ^= val;
    }
    if (anySuperWin)
      cout << "First win*";
    else if (nimXor != 0)
      cout << "First win";
    else
      cout << "Second win";
  }

int main() {

  WNumbersChessMisereMain();

  return 0;
}

