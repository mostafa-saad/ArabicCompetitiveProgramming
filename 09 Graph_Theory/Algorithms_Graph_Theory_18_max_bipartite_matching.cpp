	
	
	

	bool canMatch(int i) // O(E)
	{
		rep(j, adjMax[i]) if(adjMax[i][j] && !vis[j]) {
			vis[j] = 1;
			if( colAssign[j] < 0 || canMatch(colAssign[j]) ) {
				colAssign[j] = i, rowAssign[i] = j;
				return true;
			}
		}
		return false;
	}

	typedef vector<int>       vi;
	vector<vi> adjMax;
	vi vis, colAssign, rowAssign;

	vector< pair<int, int> > bipartiteMatching()	// O(EV)
	{	// In case spares graph, use adjList
		vector< pair<int, int> > matches;

		if(sz(adjMax) == 0)
			return matches;

		int maxFlow = 0, rows = sz(adjMax), cols = sz(adjMax[0]);
		colAssign = vi(cols, -1), rowAssign = vi(rows, -1);

		lp(i, rows) {
			vis = vi(cols, 0);
			if( canMatch(i)  )
				maxFlow++;
		}

		lp(j, cols) if(colAssign[j] != -1)
			matches.push_back( make_pair(colAssign[j], j) );
		// this is col sorted list...u can use rowAssign for reverse
		// as you see, rowAssign was not important now
		
		/*
		vector< vector<int> > mnPathCvs;
		
		lp(j, n) if(colAssign[j] == -1) {
			vector<int> v(1, j+1);
			int t = rowAssign[j];
			while(t != -1) {
				v.push_back(t+1);
				t = sz(v)%2 ? rowAssign[j] : colAssign[j] ;
			}
			mnPathCvs.push_back(v);
		}
		rep(i, mnPathCvs)
		{
			rep(j, mnPathCvs[i])	
				cout<<mnPathCvs[i][j]<<" ";
			cout<<"\n";
		}
		*/
		
		return matches;
	}
	
	
