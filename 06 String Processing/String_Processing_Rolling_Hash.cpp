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

/*
 Another base, in case needed.

 #define BASE 53ll
 #define BASE_INV 682323657ll    // pow(BASE, MOD-2)%MOD
 System.out.println(BigInteger.probablePrime(35, new Random()));

 (MOD-1)^2 and (MOD-1)*BASE_INV MUST fit in your data type(E.g. ll)


 bases 33, 37, 39, or 41 are pretty good for dictionary strings (< 7 collisions)
 */

#define MOD 2000000011ll
#define BASE 53ll
#define BASE_INV 1283018875ll   // pow(BASE, MOD-2)%MOD

ll fastpow(ll num, ll p) {
  if (p == 0)
    return 1;
  if (p % 2)
    return (num % MOD * fastpow(num, p - 1)) % MOD;
  ll a = fastpow(num, p / 2);
  return (a * a) % MOD;
}

ll removeAt(ll code, int idx, int val) {
  return (code - (val * fastpow(BASE, idx)) % MOD + MOD) % MOD;
}

ll addAt(ll code, int idx, int val) {
  return (code + (val * fastpow(BASE, idx)) % MOD) % MOD;
}

ll shiftLeft(ll code) {
  return (code * BASE) % MOD;
}

ll shiftRight(ll code) {
  return (code * BASE_INV) % MOD;
}

///////////////////////////////////////////////////////////////////////////
// better reduce chars values by reindexing
int val(char c) {
  return c;   // no reduction
  return 1 + islower(c) ? c - 'a' : c - 'A' + 26;
}

ll getHashValue1(string pat) {
  ll patCode = 0;
  for (int i = 0; i < (int) pat.size(); ++i) {
    patCode = patCode * BASE;  // left shift
    patCode += val(pat[i]);    // add value
    patCode %= MOD;            // mod to avoid overflow
  }
  return patCode;
}

ll getHashValue2(string pat) {
  ll patCode = 0;
  for (int i = 0; i < (int) pat.size(); ++i) {
    patCode = shiftLeft(patCode);
    patCode = addAt(patCode, 0, val(pat[i]));
  }
  return patCode;
}

///////////////////////////////////////////////////////////////////////////

void pattern_search(string main, string pat) {
  int n = pat.size();
  ll patCode = 0;
  for (int i = 0; i < (int) pat.size(); ++i) {
    patCode = shiftLeft(patCode);
    patCode = addAt(patCode, 0, val(pat[i]));
  }

  ll subCode = 0;
  string subStr;
  for (int i = 0; i < (int) main.size(); ++i) {
    if (i - n >= 0) {
      subCode = removeAt(subCode, n - 1, val(main[i - n]));
      subStr.erase(subStr.end() - 1);
    }
    subCode = shiftLeft(subCode);
    subCode = addAt(subCode, 0, val(main[i]));
    subStr.insert(subStr.begin(), main[i]);
    if (patCode == subCode)
      cout << subCode << "\t" << subStr << "\n";
  }
}

  // return lowest suffix index that is palindrome
  int longestSuffixPalindrome(string str) {
    int n = str.size(), longestSuffix = 0;
    ll strCode = 0, strRevCode = 0;

    // start from end, find longest suffix = reverse of suffix
    for (int i = n - 1, len = 0; i >= 0; --i, ++len) {
      strCode = shiftLeft(strCode);
      strCode = addAt(strCode, 0, str[i]);
      //Note, next is not so efficient, as we compute pow each step
      strRevCode = addAt(strRevCode, len, str[i]);

      if (strCode == strRevCode)
        longestSuffix = n - i;
    }
    return longestSuffix;
  }

  int main() {
  #ifndef ONLINE_JUDGE
    freopen("test.txt", "rt", stdin);
  #endif

    string str;
    while (getline(cin, str)) {

      int longestSuffix = longestSuffixPalindrome(str);

      cout<<str;
      // print the first few letters reversed
      for (int i = (str.size() - longestSuffix) - 1; i >= 0; i--)
        cout<<str[i];
      cout<<"\n";
    }
    return 0;
  }
