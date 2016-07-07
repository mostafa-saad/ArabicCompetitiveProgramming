#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#define all(v)            ((v).begin()), ((v).end())
#define sz(v)             ((int)((v).size()))
#define rep(i, n)         for(int i=0;i<(int)(n);++i)
#define repi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define repa(i, j, v)	  rep(i, sz(v))	rep(j, sz(v[0]))
#define lp(i, cnt)			for(int i=0;i<(cnt);++i)

typedef pair<int, int>    pii;
typedef vector<int>       vi;
typedef vector<pii>       vp;
typedef vector<string>    vs;
typedef long long         ll; 

#include <iostream>
#include <algorithm>
using namespace std;


const int N = 2000000;
bool isLucky[N+9] = {0};

const int MAX = 4194304;		//	interval 2^[F(logn)+2)]
int interval[MAX+9];

int gs = 0, ge = N-1;

int insert(int val, int s=gs, int e=ge, int p=1)
{	// return kTh of inserted POSITIVE val in O(logn)
	interval[p]++;
	if(s == e)	return interval[p]-1;	// modify this return for ur needs e.g = 0

	if((s+e)/2 >= val)
		return insert(val, s, (s+e)/2, 2*p);
	return interval[2*p] + insert( val, (s+e)/2+1, e, 2*p+1);
}

int getkTh(int kTh, int s=gs, int e=ge, int p=1)	// O(logn) updating tree intervals
{	// return kTh smallest element in O(logn).
	if(s == e)	return s;

	if(interval[2*p] >= kTh)	return getkTh(kTh, s, (s+e)/2, 2*p);
	return getkTh(kTh-interval[2*p], (s+e)/2+1, e, 2*p+1);
}

int delkTh(int kTh, int s=gs, int e=ge, int p=1)
{
	interval[p]--;
	if(s == e)	return s;

	if(interval[2*p] >= kTh)	return delkTh(kTh, s, (s+e)/2, 2*p);
	return delkTh(kTh-interval[2*p], (s+e)/2+1, e, 2*p+1);
}

int main()
{
	// Build all lucky numbers till 2000000
	for (int idx = 1; idx < N; idx+=2)
		insert(idx);
	
	isLucky[1] = 1;
	
	int avilable = 1000000;
	
	for (int start = 2 ; start <= avilable ; ++start)
	{		
		int next = 1, removed = 0, term = getkTh(start);
		isLucky[term] = 1;
		
		while(term*next-removed <= avilable) {
			delkTh(term*next-removed);
			next++, removed++, avilable--;
		}
	}
	
	int n;
	while(cin>>n)
	{
		int mid = n / 2;	// Any number is divided to 2 sides 
		
		bool found = false;
		if(n%2 == 0)
		for(int k = mid; k > 0; k --)
			if(isLucky[k] && isLucky[n-k] )
			{
				cout<<n<<" is the sum of "<<k<<" and "<<n-k<<"."<<"\n";
				found = true;
				break;
			}
		
		if(!found)
			cout<<n<<" is not the sum of two luckies!"<<"\n";	
	}
	
	
	return 0;
}

