const int MAX = 5001;
const int LOGMAX = 13;

int P[MAX][LOGMAX], parent[MAX], depth[MAX];
vector<vector<int> > tree;

void tree_dfs(int i, int p = -1, int d = 0) {
	parent[i] = p, depth[i] = d;
	lp(j, sz(tree[i]))
		if (tree[i][j] != p)
			tree_dfs(tree[i][j], i, d + 1);
}

void preprocessing(int n) // O(nlog(n)) // P[i][j] is 2^j ancestor of i
{
	memset(parent, -1, n*sizeof(int));
	lp(i, n) if(parent[i] == -1)
		tree_dfs(i, i);

	lp(i, n) {
		lp(j, 1 << j)
			P[i][j] = -1;
		P[i][0] = parent[i]; // the first ancestor of node
	}

	for (int j = 1; (1 << j) < n; j++)
		lp(i, n) //DP
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
}

//call pre-processing before using it
int LCA(int n, int p, int q) //O(log(n))
{
	if (depth[p] < depth[q])		swap(p, q);
	int log;
	for (log = 1; 1 << log <= depth[p]; log++)
		;
	log--;

	repd(i, log) //find ancestor of p on the same level with q
		if (depth[p] - (1 << i) >= depth[q])
			p = P[p][i];

	if (p == q)
		return p; //one of them parent of another

	repd(i, log) //we compute LCA(p, q) using the values in P
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];

	return parent[p];
}

int shortestPath(int n, int p, int q) {
	return depth[p]+depth[q]-2*depth[LCA(n, p, q)]+1;
}
