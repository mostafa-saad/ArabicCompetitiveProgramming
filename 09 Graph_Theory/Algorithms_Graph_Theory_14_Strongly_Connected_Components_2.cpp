vector< vector<int> > adjList, comps, dagList;
vector<int> inStack, lowLink, dfn, comp, inDeg, outDeg;
stack<int> stk;
int ndfn, cntSrc, cntSnk;

void tarjan(int node) {
	lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
	stk.push(node);

	rep(i, adjList[node]) {
		int ch = adjList[node][i];
		if (dfn[ch] == -1) {
			tarjan(ch);
			lowLink[node] = min(lowLink[node], lowLink[ch]);
		} else if (inStack[ch])
			lowLink[node] = min(lowLink[node], dfn[ch]);
	}

	if (lowLink[node] == dfn[node]) {
		comps.push_back(vector<int> ());
		int x = -1;
		while (x != node) {
			x = stk.top(), stk.pop(), inStack[x] = 0;
			comps.back().push_back(x);
			comp[x] = sz(comps) - 1;
		}
	}
}

void scc() {
	int n = sz(adjList);

	inStack.clear();	inStack.resize(n);
	lowLink.clear();	lowLink.resize(n);
	dfn.clear();		dfn.resize(n, -1);
	ndfn = 0;

	comp.clear(), comp.resize(n);
	comps.clear();

	lp(i, n) if (dfn[i] == -1)
		tarjan(i);
}

void computeCompGraph() {
	int csz = comps.size(), cntSrc = csz, cntSnk = csz;

	outDeg.clear();		outDeg.resize(csz);
	inDeg.clear();		inDeg.resize(comps.size());
	dagList.clear();		dagList.resize(csz);	//will contain duplicates

	for (int i = 0; i < sz(adjList); i++)
		for (int j = 0; j < sz(adjList[i]); j++) {
			int k = adjList[i][j];
			if (comp[k] != comp[i]) {
				dagList[comp[i]].push_back(comp[k]);	//reverse
				if (!(inDeg[comp[k]]++))		cntSrc--;
				if (!(outDeg[comp[i]]++))		cntSnk--;
			} else
				;// this edge is for a component comp[k]
		}

	/* Min edges to convert DAG to one cycle
	if (comps.size() == 1)
		cout << "0\n";
	else {
		cout << max(cntSrc, cntSnk) << "\n";
	}
	*/
}

int main() {
	freopen("b.in", "rt", stdin);

	int cases;
	cin >> cases;

	while (cases--) {
		int n, m;
		cin >> n >> m;
		adjList.clear();
		adjList = vector<vector<int> > (n);

		lp(i, m) {
			int f, t;
			cin >> f >> t;
			f--, t--;
			adjList[f].push_back(t);
		}

		scc();
		computeCompGraph();

	}

	return 0;
}

	
	

// Kosaraju’s algorithm
// http://www.geeksforgeeks.org/strongly-connected-components/
void dfs_topsort(vvi& adj, vector<bool>& used, vi& topsort, int node)
{
	int i;
	used[node] = true;
	for (i=0;i<sz(adj[node]); ++i)
		if (!used[ adj[node][i] ])
			dfs_topsort(adj, used, topsort, adj[node][i]);
	topsort.push_back(node);
}

void dfs_scc(vvi& transpose, vector<bool>& used, vi& scc, int node)
{
	int i;
	used[node] = true;
	for (i=0;i<sz(transpose[node]) ; ++i)
		if (!used[transpose[node][i]])
		{
			scc[transpose[node][i]] = scc[node];
			dfs_scc(transpose, used, scc, transpose[node][i]);
		}
}

void SCC_main()	//Kosaraju's algorithm O(E+V)
{
	int v, e, from, to;

	cin>>v>>e;
	vvi adj(v), transpose(v);
	vi scc(v), numof_scc, topsort;
	vector<bool> used(v, false), used2(v, false);

	lp(i, e) {
		cin>>from>>to;
		adj[from-1].push_back(to-1);
		transpose[to-1].push_back(from-1);
 	}

	lp(i, v) if (!used[i]) dfs_topsort(adj, used, topsort, i);

	lpd(j, v-1, 0) //Start from end as dfs_topsort reverse them.
	{
		int i = topsort[j];
		if (!used2[i]) {
			numof_scc.push_back(i);  scc[i] = i; //Mark as a SCC
			dfs_scc(transpose, used2, scc, i);
		}
	}

	sort( all(numof_scc) );
	numof_scc = vi(numof_scc.begin(), unique(all(numof_scc)));

	cout<<"# SCC " <<numof_scc.size()<<"\n";

	vvi comps(v);
	lp(i, v) comps[scc[i]].push_back(i);

	lp(i, v) {
		lp(j, comps[i].size()) cout<<comps[i][j]+1<<" ";
		if(comps[i].size() != 0)	cout<<"\n";
	}
}



// Simple one...N^3
void SCC2(bool reach[MAX][MAX], int n, bool compGraph[MAX][MAX], int & m)
{
	rep(k, n) rep(i, n)	rep(j, n)	// Warshl Transitive clousre
		reach[i][j] |= (reach[i][k] && reach[k][j]);

	vector<int> comp(n, -1);

	int next = 0;
	rep(i, n) if(comp[i]==-1) {
		comp[i] = next++;
		rep(j, n) if(reach[i][j] && reach[j][i])	comp[j] = comp[i];
	}

	rep(i, n)	rep(j, n)	if(reach[i][j])
		compGraph[ comp[i] ][ comp[j] ] = 1;	// DAG

	m = next;
}




