#include <bits/stdc++.h>
using namespace std;

// Original (elegant) source: http://codeforces.com/blog/entry/22072
// Heavy-light Decomposition to compute max query on path: http://www.spoj.com/problems/QTREE/

const int N = 10000 + 9;
const int SEG_MAX = 32770 + 9;   //L = Ceil(log2(V)).  TREE_SIZE = 2 + (1<<(L+1))
int interval[SEG_MAX];
int mxV;  // current # of tree nodes

struct SegmentTree {  // Range Max Query
  int idx, val, from, to;

  void init(int n) {
    mxV = n;
    memset(interval, 0, n * sizeof(int));
  }
  // Initialize idx & val before update
  int update(int s = 0, int e = mxV, int p = 1) {
    if (s == e)
      return interval[p] = val;
    int mid = (s + e) / 2;
    if (idx <= mid)
      update(s, (s + e) / 2, 2 * p);
    else if (idx > mid)
      update((s + e) / 2 + 1, e, 2 * p + 1);
    return interval[p] = max(interval[2 * p], interval[2 * p + 1]);
  }
  // Initialize from & to before query
  int query(int s = 0, int e = mxV, int p = 1) {
    if (from <= s && to >= e)
      return interval[p];
    int mid = (s + e) / 2;
    if (to <= mid)
      return query(s, (s + e) / 2, 2 * p);
    if (from > mid)
      return query((s + e) / 2 + 1, e, 2 * p + 1);
    int a = query(s, (s + e) / 2, 2 * p);
    int b = query((s + e) / 2 + 1, e, 2 * p + 1);
    return max(a, b);
  }
};

/////////////////////////////////////////////////////////////////////////////////////

const int isValueOnEdge = 1;  // switch to 0 for value on node
vector<vector<int>> tree;     // undirected tree
// For values on edge
vector<vector<int>> treeEdgeIdx;
vector<int> edge_to;    // which end point used in directing the edge
vector<int> edge_cost;

struct HeavyLight {
  int parent[N], depth[N], heavy[N], root[N], segTreePos[N];
  int queryRes;  // e.g. max value on path
  SegmentTree segTree;

  int dfs_hld(int v) {
    int size = 1, maxSubtree = 0;
    for (int k = 0; k < (int) tree[v].size(); ++k) {
      int u = tree[v][k], edgeIdx = treeEdgeIdx[v][k];
      if (u != parent[v]) {
        edge_to[edgeIdx] = u;
        parent[u] = v, depth[u] = depth[v] + 1;
        int childTreeSize = dfs_hld(u);
        if (childTreeSize > maxSubtree)
          heavy[v] = u, maxSubtree = childTreeSize;
        size += childTreeSize;
      }
    }
    return size;
  }
  void buildChains() {
    int n = tree.size();
    memset(heavy, -1, n * sizeof(int));
    parent[0] = -1, depth[0] = 0;
    dfs_hld(0);

    // Connect chains to its root. Map chain to segment tree part
    for (int chainRoot = 0, pos = 0; chainRoot < n; ++chainRoot) {
      if (parent[chainRoot] == -1 || heavy[parent[chainRoot]] != chainRoot) {
        for (int j = chainRoot; j != -1; j = heavy[j])  // iterate on a chain
          root[j] = chainRoot, segTreePos[j] = pos++;
      }
    }
    segTree.init(n);
  }
  void queryChain(int l, int r) {
    segTree.from = l, segTree.to = r;
    queryRes = max(queryRes, segTree.query());
  }
  int queryPath(int u, int v) {
    queryRes = 0;  // be careful from u = v for isValueOnEdge
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth[root[u]] > depth[root[v]])
        swap(u, v);
      queryChain(segTreePos[root[v]], segTreePos[v]);
    }
    if (depth[u] > depth[v])
      swap(u, v);
    if (!isValueOnEdge || u != v)
      queryChain(segTreePos[u] + isValueOnEdge, segTreePos[v]);
    return queryRes;  // u = LCA node
  }
  // For value on DIRECTED edge (f, t, value), call update_node(t, value)
  void updatePos(int treeNode, int value) {
    segTree.idx = segTreePos[treeNode], segTree.val = value;
    segTree.update();
  }
};
/////////////////////////////////////////////////////////////////////////////////////

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif
  int cases;
  scanf("%d", &cases);

  HeavyLight hdl;

  for (int cc = 0; cc < cases; ++cc) {
    int n;
    scanf("%d", &n);
    tree.clear(), edge_cost.clear(), treeEdgeIdx.clear(), edge_to.clear();
    tree.resize(n), edge_cost.resize(n), treeEdgeIdx.resize(n), edge_to.resize(n);

    for (int i = 0; i < n - 1; ++i) {
      int f, t, c;
      scanf("%d%d%d", &f, &t, &c);

      tree[f - 1].push_back(t - 1), tree[t - 1].push_back(f - 1);
      treeEdgeIdx[f - 1].push_back(i), treeEdgeIdx[t - 1].push_back(i);
      edge_cost[i] = c;
    }
    hdl.buildChains();
    for (int i = 0; i < n - 1; ++i)
      hdl.updatePos(edge_to[i], edge_cost[i]);

    char s[100];
    while (scanf("%s", s) && s[0] != 'D') {
      int a, b;
      scanf("%d%d", &a, &b);

      if (s[0] != 'Q')
        hdl.updatePos(edge_to[a - 1], b);
      else
        printf("%d\n", hdl.queryPath(a - 1, b - 1));
    }
  }
  return 0;
}
