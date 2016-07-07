#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
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


const int MAX = 26+1;		//+1 to assign starting from 1
//TODO: Input limits, to be modified
const int MAX_PAT_LEN = 15;
const int MAX_PATS 	  = 30;
char pats[MAX_PATS][MAX_PAT_LEN];

int nextNodeId = 0;

int cIdx(char c) {
	return 1 + c-'a';
	//return c;		//in case any problems
}

//you can either use Large MAX (e.g. 260) or reassign string to smalled indices
struct node {
	node* fail;
	node* child[MAX];
	vector<int> patIdx;
	vector<char> chars;
	int id;

	node() {
		clr(child, 0);
		id = nextNodeId++;
	}

	void insert(char* str, int idx, bool firstCall = true) {
		// You can remove next part, it just reassign string to indices to keep small mem
		if(firstCall) {
			char *t = str;
			while(*t) *t = cIdx(*t), t++;
		}
		/////////////////////////////////

		if (!*str) {
			patIdx.push_back(idx);
		} else {
			if (!child[*str]) {
				child[*str] = new node();
				chars.push_back(*str);
			}
			child[*str]->insert(str + 1, idx, false);
		}
	}
};

void move(node* &k, char c) {
	while (!k->child[c])
		k = k->fail;
	k = k->child[c];
}

node* buildAhoTree(char pat[][MAX_PAT_LEN], int len) {
	node * root = new node();

	lp(i, len) {
		root->insert(pat[i], i);
	}

	queue<node*> q;

	lp(i, MAX)
		if (root->child[i])
			q.push(root->child[i]), root->child[i]->fail = root;
		else
			root->child[i] = root; //Sentinel

	node* cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		rep(i, cur->chars) {
			int ch = cur->chars[i];
			q.push(cur->child[ch]);
			node* k = cur->fail;

			move(k, ch);

			cur->child[ch]->fail = k;

			cur->child[ch]->patIdx.insert(cur->child[ch]->patIdx.end(), all(k->patIdx));
		}
	}
	return root;
}

void match(const char* str, node* root, vector<vector<int> > & res) {
	node* k = root;

	for (int i = 0; str[i]; i++) {
		move(k, str[i]);
		rep(j, k->patIdx)
			res[k->patIdx[j]].push_back(i);
	}
}
int main() {

	scanf("%s", arr);

	int k;
	scanf("%d", &k);

	lp(i, k) {
		scanf("%s", &pats[i]);
	}
	node* root = buildAhoTree(pats, k);

	vector<vector<int> > res(k);
	match(arr, root, res);

	lp(i, k) {
		if (sz(res[i]))
			printf("y\n");
		else
			printf("n\n");
	}

	return 0;
}
