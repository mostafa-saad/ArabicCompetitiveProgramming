#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
int oo=0x7FFFFFFF;
ll dp[60][60];
char s[61];
int n;
ll calc(int f,int t)
{
	if(dp[f][t]!=-1)
		return dp[f][t];
	ll ret=1;
	for(int i=f+1;i<t;i++)
		for(int j=i;j<t;j++)
			if(s[i]==s[j])
				ret+=1+calc(i,j);
	return dp[f][t]=ret;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("a.txt","rt",stdin);
    #endif
    int N;
    scanf("%d",&N);
    rep(nn,N)
    {
        scanf("%s",s);
    	n=strlen(s);
    	mem(dp,-1);
    	ll ret=0;
    	rep(i,n)
			for(int j=i;j<n;j++)		// O() ?
				if(s[i]==s[j])
					ret+=1+calc(i,j);
    	cout<<ret/2<<endl;
    }
    return 0;
}
