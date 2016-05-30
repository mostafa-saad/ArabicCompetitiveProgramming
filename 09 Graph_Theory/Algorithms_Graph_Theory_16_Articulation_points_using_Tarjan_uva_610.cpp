#pragma warning(disable:4786)
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <string>
using namespace std; 

const int MAX		  = 10000;
const int NOT_VISITED = -1;

int dfn[MAX], low[MAX];
bool visited[MAX], root;
set<int> artpoints;		//For removing arts if repetation
vector< vector<int> > graph;

stack< pair<int, int> > component;	//pair<int, int> is edge[u--v]

int num;

int min(int a, int b)
{
	return (a<b)?a:b;
}

void init(int n)
{
	num = 0;
	artpoints.clear();
	graph.clear();
	graph.resize(n);

	int i;
	for(i=0;i<n;i++)
	{
		visited[i] = false;
		dfn[i] = low[i] = NOT_VISITED;
	}	
}

void bicon(int u, int v)	//O(n+e)
{
	int i, w;
	pair<int, int> edge;
	dfn[u] = low[u] = num++;

	for(i=0;i<graph[u].size();i++)
	{
		w = graph[u][i];
		if(v!=w && dfn[w]<dfn[u])
			component.push( make_pair(u, w));

		if(dfn[w] == NOT_VISITED)	// for each bcc, happens once ONLY
		{
			bicon(w, u);
			low[u] = min(low[u], low[w]);

			if(low[w] >= dfn[u])
			{
				if (dfn[u]==0 && root==false)
					root=true;
				else
					artpoints.insert(u);

				int cnt = 0;
				do
				{
					cnt++;
					edge = component.top();
					component.pop();
					cout<<edge.first+1<<" "<<edge.second+1<<"\n"; 
				}while(edge.first != u || edge.second != w);

				if(cnt == 1)
					cout<<edge.second+1<<" "<<edge.first+1<<"\n"; 
			}
		}
		else if(w != v)
			low[u] = min(low[u], dfn[w]);
	}		
}

void dfnlow(int u, int v)	//Just for calcing Tw tabels
{
	int i, w;

	dfn[u] = low[u] = num++;
	for(i=0;i<graph[u].size();i++)
	{
		w = graph[u][i];
		if(dfn[w] <= NOT_VISITED)
		{
			dfnlow(w, u);
			low[u] = min(low[u], low[w]);
		}
		else if(w != v)
			low[u] = min(low[u], dfn[w]); 
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("test.txt", "rt", stdin);
#endif

	int i, n, links, from, to;

	int cases = 1;

	while(cin>>n>>links)
	{
		if(!n && !links)
			break;

		
		init(n);
		for(i=0;i<links;i++)
		{
			cin>>from>>to;
			graph[from-1].push_back(to-1);
			graph[to-1].push_back(from-1);
		}

		cout<<cases++<<"\n\n";
		bicon(0, NOT_VISITED);
		cout<<"#\n";
	}
	return 0;
}
/*
Input
10 11
0 1
1 2
1 3
2 4
4 3
3 5
5 6
5 7
6 7
7 9
7 8
*/
