#include <bits/stdc++.h>
using namespace std;

#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;

const int INP_SIZE = 30000+9;
const int QUERIES_SIZE = 200000+9;
const int SQRTN = 175;  // sqrt(INP_SIZE)

struct query {
  int l, r, q_idx, block_idx;

  query() {}
  query(int _l, int _r, int _q_idx) {
    l = _l - 1, r = _r - 1, q_idx = _q_idx, block_idx = _l / SQRTN;
  }
  bool operator <(const query &y) const {
    if (block_idx != y.block_idx)
      return block_idx < y.block_idx;
    return r < y.r;
  }
};

int n, m; // input size and queries
int inp[INP_SIZE], result = 0;
int q_ans[QUERIES_SIZE];
query queries[QUERIES_SIZE];

// You need to update following data structure
  // per problem (e.g. use mutliset)
int cnt[1000000 + 9];

// You need to update these 2 methods per a problem
void add(int idx) {
  cnt[inp[idx]]++;
  if (cnt[inp[idx]] == 3)
    result++;
}

void remove(int idx) {
  cnt[inp[idx]]--;
  if (cnt[inp[idx]] == 2)
    result--;
}

void process() {  // don't change
  sort(queries, queries+m);

  int curL = 1, curR = 0; // tricky initialization and indexing
  for (int i = 0; i < m; i++) {
    while (curL < queries[i].l) remove(curL++);
    while (curL > queries[i].l) add(--curL);
    while (curR < queries[i].r) add(++curR);
    while (curR > queries[i].r) remove(curR--);
    q_ans[queries[i].q_idx] = result;
  }
}

//////////////

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &inp[i]);

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int left, right;
    scanf("%d%d", &left, &right);
    queries[i] = query(left, right, i);
  }
  process();

  for (int i = 0; i < m; i++)
    printf("%d\n", q_ans[i]);
}
