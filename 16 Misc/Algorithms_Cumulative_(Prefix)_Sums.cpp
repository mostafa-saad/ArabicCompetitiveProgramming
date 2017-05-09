#include <bits/stdc++.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef long double ld;

int sum_range1(int S, int E, vector<int> & cum_sum) {
  if (S == 0)
    return cum_sum[E];

  return cum_sum[E] - cum_sum[S - 1];
}

void zero_based() {
  vector<int> A = { 2, 1, 4, 5, 3, 7 };
  vector<int> S(A.size(), 0);

  //pre-processing: Compute cumulative sum array
  for (int i = 0; i < (int) A.size(); i++)
    S[i] += (i == 0) ? A[i] : A[i] + S[i - 1];

  cout << sum_range1(0, 5, S) << "\n";
  cout << sum_range1(1, 5, S) << "\n";
  cout << sum_range1(2, 4, S) << "\n";
}

int sum_range2(int S, int E, vector<int> & cum_sum) {
  return cum_sum[E] - cum_sum[S - 1];
}

void one_based() {
  vector<int> A = { 0, 2, 1, 4, 5, 3, 7 };  // let A[0] = 0
  vector<int> S(A.size(), 0);

  //pre-processing: Compute cumulative sum array: Start from 1
  for (int i = 1; i < (int) A.size(); i++)
    S[i] += A[i] + S[i - 1];

  // 1-based queries
  cout << sum_range1(1, 6, S) << "\n";
  cout << sum_range1(2, 6, S) << "\n";
  cout << sum_range1(3, 5, S) << "\n";
}

  // sum((i, j) (k, l)) where (k, l) is the bottom right
  int sum_range(int i, int j, int k, int l, vector<vector<int>> & S) {
    return S[k][l] - S[k][j-1] - S[i-1][l] + S[i-1][j-1];
  }

  void accumSum2D() {
    // 1-based matrix
    // Append extra top row and col with zero
    vector<vector<int>> A =
        { { 0, 0, 0, 0, 0, 0 },
          { 0, 1, 2, 2, 4, 1 },
          { 0, 3, 4, 1, 5, 2 },
          { 0, 2, 3, 3, 2, 4 },
          { 0, 4, 1, 5, 4, 6 },
          { 0, 6, 3, 2, 1, 3 }, };

    // Accumulate each row
    for (int i = 1; i < (int) A.size(); i++)
      for (int j = 1; j < (int) A[0].size(); j++)
        A[i][j] += A[i][j-1];

    // Accumulate each col
    for (int j = 1; j < (int) A[0].size(); j++)
      for (int i = 1; i < (int) A.size(); i++)
          A[i][j] += A[i-1][j];

    // 1, 5, 2
    // 3, 2, 4
    cout << sum_range(2, 3, 3, 5, A) << "\n";
  }

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif

  accumSum2D();

  return 0;
}
