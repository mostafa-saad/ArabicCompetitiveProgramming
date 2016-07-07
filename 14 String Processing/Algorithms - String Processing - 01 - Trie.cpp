/*
 * trie.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: Mostafa Saad
 */



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
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;


const int MAX_CHAR = 26;

struct trie {
	trie* child[MAX_CHAR];
	bool isLeaf;

	trie() {
		memset(child, 0, sizeof(child));
		isLeaf = 0;
	}

	void insert(char *str) {
		if(*str == '\0')
			isLeaf = 1;
		else {
			int cur = *str - 'a';
			if(child[cur] == 0 )
				child[cur] = new trie();
			child[cur]->insert(str+1);
		}
	}

	bool wordExist(char* str) {
		if(*str == '\0')
			return isLeaf;

		int cur = *str - 'a';
		if(child[cur] == 0 )
			return false;	// such path don't exist

		return child[cur]->wordExist(str+1);
	}

	bool prefixExist(char* str) {
		if(*str == '\0')
			return true;

		int cur = *str - 'a';
		if(child[cur] == 0 )
			return false;	// such path don't exist

		return child[cur]->prefixExist(str+1);
	}
};


int main()
{
	trie root;

	root.insert("abcd");
	root.insert("xyz");
	root.insert("abf");
	root.insert("xn");
	root.insert("ab");
	root.insert("bcd");

	cout<<root.wordExist("xyz")<<"\n";
	cout<<root.wordExist("xy")<<"\n";
	cout<<root.prefixExist("xyz")<<"\n";

	return 0;
}
