/*
 *
 *  Created on: Dec 11, 2016
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

bool do_print = true;

int grundy[120];

int calcMex(unordered_set<int> hashtable) {
  int val = 0;

  while (hashtable.find(val) != hashtable.end())
    val++;
  return (val);
}

// let a grid with no heads (TTTTT) has grundy = 0
// Compute grundy when 1 head at pos
int calcGrundyMockTurtle(int pos) {
  if (pos == 0)
    return 1;   // notice grundy(0) = 1

  int &ret = grundy[pos];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  // 1: flip 1 coin. Now state us TTTTT => grundy = 0
  sub_nimbers.insert(0);

  // 2: flip 2 coins: me and another.
  // e.g. TTTTTTH => TTTHTTT
  for (int i = 0; i < pos; ++i)
    sub_nimbers.insert(calcGrundyMockTurtle(i));

  // 3: flip 3 coins: me and other 2 coins (tricky)
  // e.g. TTTTTTH => THTHTTT
  // THTHTTT has 2 heads, 2 independent game from 1 a single move
  for (int i = 0; i < pos; ++i)  /// I turn another 2
    for (int j = i + 1; j < pos; ++j)
      sub_nimbers.insert(calcGrundyMockTurtle(i) ^ calcGrundyMockTurtle(j));

  return ret = calcMex(sub_nimbers);
}

void calcGrundyMockTurtle_main() {
  clr(grundy, -1);

  for (int i = 0; i < 30; ++i) {
    int ans = calcGrundyMockTurtle(i);
    if (do_print)
      cout << ans << " ";
    int f = 1 - __builtin_popcount(i) % 2;
    assert(ans == 2 * i + f);  // ith odious number
  }
  // g(x): 1 2 4 7 8 11 13 14 16 19 21 = odious sequence
  if (do_print)
    cout << "\n";
}

/////////////////////////////////////////////////////////////////

// let a grid with no heads (TTTTT) has grundy = 0
// Compute grundy when 1 head at pos
// Assuming indexing from 1 (e.g. g(0) = 0)
// This is different handling when we assumed 0-indexing
int calcGrundyRulerTurtle(int pos) {
  if (pos == 0)
    return 0;   // notice grundy(0) = 1

  int &ret = grundy[pos];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  // 1: flip 1 coin. Now state us TTTTT => grundy = 0
  sub_nimbers.insert(0);

  // 2: flip any left, but consecutive
  // e.g. TTTTH = {TTTTT, TTTHT, TTHHT, THHHT, HHHHT}
  int xorVal = 0;
  for (int i = pos - 1; i >= 0; --i) {
    // Each move create pos-i independent sub-games
    xorVal ^= calcGrundyRulerTurtle(i);
    sub_nimbers.insert(xorVal);
  }
  return ret = calcMex(sub_nimbers);
}

void calcGrundyRulerTurtle_main() {
  clr(grundy, -1);

  for (int i = 1; i < 30; ++i) {  // indexing from 1
    int ans = calcGrundyRulerTurtle(i);
    // g(x) is the largest power of 2 dividing x
    assert(ans == (i & -i));
    if (do_print)
      cout << ans << " ";
  }
  // g(x): 1 2 1 4 1 2 1 8 1 2 1 4 1 2 1 16 1 2 1
  if (do_print)
    cout << "\n";
}

/////////////////////////////////////////////////////////////////

int calcGrundyGruntTurtle(int pos) {
  if (pos < 3)
    return 0;

  int &ret = grundy[pos];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;
  // E.g. 0, x, n − x, n for some 1 ≤ x < n/2
  // handle even/odd cases carefully
  for (int i = 1; i <= pos / 2; ++i)
    if (i != pos - i)
      sub_nimbers.insert(calcGrundyGruntTurtle(i) ^ calcGrundyGruntTurtle(pos - i));

  return ret = calcMex(sub_nimbers);
}

void calcGrundyGruntTurtle_main() {
  clr(grundy, -1);

  for (int i = 0; i < 50; ++i) {
    int ans = calcGrundyGruntTurtle(i);
    cout << ans << " ";
  }
  // g(x): 0 0 0 1 0 2 1 0 2 1 0 2 1 3 2 1 3 2 4 3 0 4 3 0 4 3 0 4 1 2 3 1 2 4 1 2 4 1 2 4 1 5 4 1 5 4 1 5 4 1
  cout << "\n";
}

/////////////////////////////////////////////////////////////////

int grundy2[120][120];

int calcGrundyAcrosticTwins(int x, int y) {
  if (x == 0 && y == 0)
    return 0;

  int &ret = grundy2[x][y];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  for (int i = 0; i < y; i++)
    sub_nimbers.insert(calcGrundyAcrosticTwins(x, i));

  for (int i = 0; i < x; ++i)
    sub_nimbers.insert(calcGrundyAcrosticTwins(i, y));

  return ret = calcMex(sub_nimbers);
}

void calcGrundyAcrosticTwins_main() {
  clr(grundy2, -1);

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      int ans = calcGrundyAcrosticTwins(i, j);
      cout << setw(2) << ans << " ";

      assert(ans == (i ^ j));   // (x, y) is 2 normal piles :)
    }
    cout << "\n";
  }
}

/////////////////////////////////////////////////////////////////

// aka nim multiplication
int calcGrundyTurningCorners(int x, int y) {  // O(N^4)
  if (x == 0 && y == 0)
    return 0;

  int &ret = grundy2[x][y];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  for (int a = 0; a < x; ++a)
    for (int b = 0; b < y; ++b)
      sub_nimbers.insert(calcGrundyTurningCorners(a, b) ^ calcGrundyTurningCorners(a, y) ^ calcGrundyTurningCorners(x, b));

  return ret = calcMex(sub_nimbers);
}

void calcGrundyTurningCorners_main() {
  clr(grundy2, -1);

  for (int i = 0; i < 16; ++i) {
    for (int j = 0; j < 16; ++j) {
      int ans = calcGrundyTurningCorners(i, j);
      if (do_print)
        cout << setw(2) << ans << " ";
    }
    if (do_print)
      cout << "\n";
  }
}

/////////////////////////////////////////////////////////////////

// Probably using table method will reduce order to O(N^4)
int calcGrundyRugsSlow(int x, int y) {  // 1-based
  if (x == 0 && y == 0)
    return 0;

  int &ret = grundy2[x][y];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  for (int a = 1; a <= x; ++a)
    for (int b = 1; b <= y; ++b) {
      int xorVal = 0;  // compute rect xor value
      for (int i = a; i <= x; ++i)
        for (int j = b; j <= y; ++j)
          if (i != x || j != y)
            xorVal ^= calcGrundyRugsSlow(i, j);

      sub_nimbers.insert(xorVal);
    }
  return ret = calcMex(sub_nimbers);
}

void calcGrundyRugsSlow_main() {
  clr(grundy2, -1);

  for (int i = 1; i < 9; ++i) {
    for (int j = 1; j < 9; ++j) {
      int ans = calcGrundyRugsSlow(i, j);
      cout << setw(2) << ans << " ";
    }
    cout << "\n";
  }
}

/////////////////////////////////////////////////////////////////

int solveTitanTheorem_rugs(int x, int y) {
  int grundy1 = calcGrundyRulerTurtle(x);
  int grundy2 = calcGrundyRulerTurtle(y);
  int grundy = calcGrundyTurningCorners(grundy1, grundy2);
  return grundy;
}
void calcGrundyRugsTheorem_main() {
  do_print = false;
  // Compute nim multiplication
  calcGrundyTurningCorners_main();
  // Compute 1D ruler
  calcGrundyRulerTurtle_main();
  do_print = true;

  for (int i = 1; i < 9; ++i) {
    for (int j = 1; j < 9; ++j) {
      cout << setw(2) << solveTitanTheorem_rugs(i, j) << " ";
    }
    cout << "\n";
  }
  // Now solve whole input given H's
  int nimXor = 0, heads;

  cin >> heads;
  for (int d = 0; d < heads; ++d) {
    int x, y;
    cin >> x >> y;  // 1-based
    nimXor ^= solveTitanTheorem_rugs(x, y);
    // Recall, we xor among different grundies
    // We are doing Nim Additions over Nim Multiplications
  }
  if (nimXor != 0)
    cout << "First win";
  else
    cout << "Second win";
}

/////////////////////////////////////////////////////////////////


  int solveTitanTheoremMockTurtlesSquared(int x, int y) {
    int grundy1 = calcGrundyMockTurtle(x);
    int grundy2 = calcGrundyMockTurtle(y);
    int grundy = calcGrundyTurningCorners(grundy1, grundy2);
    return grundy;
  }

  // Find a move from (v1, v2) that has grundy target_u > 0
    // return only its top-left corner
  // Fixed in our method
  // We may implement this method in more efficient ways for queries
    // (u1⊗u2)⊕(u1⊗v2)⊕(v1⊗u2)=u.   // Add v1⊗v2 to both sides
    // (u1⊗u2)⊕(u1⊗v2)⊕(v1⊗u2)⊕(v1⊗v2)=u⊕(v1⊗v2)
    // (u1⊕v1)⊗(u2⊕v2)=u⊕(v1⊗v2) => Decoupled to 2 1d processing
    // See: http://www.stat.berkeley.edu/~mlugo/stat155-f11/tartan2.pdf
  pair<int, int> findTurningCornersMove(int v1, int v2, int target_u) {
    for (int u1 = 0; u1 < v1; ++u1)
      for (int u2 = 0; u2 < v2; ++u2) {
        int grundy =  calcGrundyTurningCorners(u1, u2) ^
                      calcGrundyTurningCorners(u1, v2) ^
                      calcGrundyTurningCorners(v1, u2);
        if (grundy == target_u)
          return {u1, u2};
      }
    return {-1, -1};  // no solution
  }

  // Find a move from pos that has grundy target_u
  // From problem to another, write yours
  vector<int> findMockTurtleMove(int pos, int target_u) {
    vector<int> ret = {pos};
    for (int i = 0; i < pos; ++i) {
      int grundy = calcGrundyMockTurtle(i);
      if (grundy == target_u)
      {
        ret.push_back(i);
        return ret;
      }
    }

    for (int i = 0; i < pos; ++i)
      for (int j = i + 1; j < pos; ++j) {
        int grundy =  calcGrundyMockTurtle(i) ^
                      calcGrundyMockTurtle(j);
        if (grundy == target_u)
        {
          ret.push_back(i);
          ret.push_back(j);
          return ret;
        }
      }
    return ret;
  }

  vector< pair<int, int> > findMockTurtleSquaredMove(int x, int y, int u) {
    int v1 = calcGrundyMockTurtle(x);
    int v2 = calcGrundyMockTurtle(y);
    pair<int, int> p = findTurningCornersMove(v1, v2, u);

    if(p.first < 0 || p.second < 0)
      return {};

    vector<int> m1 = findMockTurtleMove(x, p.first);
    vector<int> m2 = findMockTurtleMove(y, p.second);

    vector< pair<int, int> > moves;
    int computed_u = 0;

    for(auto xx : m1) for(auto yy : m2) // move multiplication
    {
      moves.push_back({xx, yy});
      if(xx == x && yy == y)
        continue;
      computed_u ^= solveTitanTheoremMockTurtlesSquared(xx, yy);
    }
    assert(u == computed_u);
    return moves;
  }


  void calcGrundyMockTurtleSquaredTheorem_main() {
  // Compute nim multiplication
    calcGrundyTurningCorners_main();
  // Compute 1D Mock Turtle
    calcGrundyMockTurtle_main();

  // Now solve whole input given H's
    int nimXor = 0, heads;

    cin >> heads;
    vector< pair<int, int> > inputPos;
    for (int d = 0; d < heads; ++d) {
      int x, y;
      cin >> x >> y;  // 0-based
      nimXor ^= solveTitanTheoremMockTurtlesSquared(x, y);
      inputPos.push_back({x, y});
    }

    if (nimXor != 0)
    {
      // Based on game, the closest H to (0, 0) won't have moves
      // Let's randomize as a general handling (hopefully faster)
      random_shuffle(inputPos.begin(), inputPos.end());
      bool foundMove = false;
      for (int d = 0; d < heads; ++d) {
        int x = inputPos[d].first, y = inputPos[d].second;
        int curg = solveTitanTheoremMockTurtlesSquared(x, y);
        vector< pair<int, int> > moves =
            findMockTurtleSquaredMove(x, y, nimXor ^ curg);

        if(moves.size() > 0) {
          foundMove = true;
          cout << "\n\n\nFirst win\n";
          for(auto p : moves)
            cout<<"Flip coin at "<<p.first<<", "<<p.second<<"\n";
          break;
        }
      }
      assert(foundMove);
    }
    else
      cout << "Second win";
  }

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif

  calcGrundyMockTurtleSquaredTheorem_main();

  return 0;
}

