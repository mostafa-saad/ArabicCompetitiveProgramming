// Suffix array algorithms (nlognlog and nlogn) are from my oach Mohamed Abd Wahab, aka Fegla

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define all(v)      ((v).begin()), ((v).end())
#define sz(v)     ((int)((v).size()))
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)
typedef long long ll;

void buildSuffixArraySlow(string str) {
  map<string, int> suffix_idx_map;
  vector<string> suffixes;

  for (int i = 0; i <= (int) str.size(); i++) {
    string suffix = str.substr(i, str.size() - i);
    suffix_idx_map[suffix] = i;
    suffixes.push_back(suffix);
  }
  sort(suffixes.begin(), suffixes.end());
  for (int i = 0; i < (int) suffixes.size(); i++)
    cout << suffixes[i] << "\t" << suffix_idx_map[suffixes[i]] << "\n";
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////

// Use N_LOGN_LOGN and N_LOGN to switch between 2 codes if needed

const int MAXLENGTH = 5000;

char str[MAXLENGTH + 1];      //the string we are building its suffix array
int suf[MAXLENGTH + 1];//the sorted array of suffix indices
int group[MAXLENGTH + 1];//In ith iteration: what is the group of the suffix index
int sorGroup[MAXLENGTH + 1];//temp array to build grouping of ith iteration

struct comp//compare to suffixes on the first 2h chars
{
  int h;
  comp(int h)
  : h(h) {
  }

  bool operator()(int i, int j) {
    if (group[i] != group[j])     // previous h-groups are different
    return group[i] < group[j];
    return group[i + h] < group[j + h];
  }
};

void print_suffix(int suf_pos, int n) {
  for (int j = suf_pos; j < n - 1; ++j)  // n-1 is string length NOT n
    cout << str[j];
}

void buildSuffixArray() {
  int n;  //number of suffixes = 1+strlen(str)
  //Initially assume that the group index is the ASCII
  for (n = 0; n - 1 < 0 || str[n - 1]; n++)
  suf[n] = n, group[n] = str[n];//code of the first char in the suffix

  sort(suf, suf + n, comp(0));//sort the array the suf on the first char only
  sorGroup[0] = sorGroup[n - 1] = 0;

  //loop until the number of groups=number of suffixes
  for (int h = 1; sorGroup[n - 1] != n - 1; h <<= 1) {
    sort(suf, suf + n, comp(h));  //sort the array using the first 2h chars

    for (int i = 1; i < n; i++)//compute the 2h group data given h group data
    sorGroup[i] = sorGroup[i - 1] + comp(h)(suf[i - 1], suf[i]);

    for (int i = 0; i < n; i++)//copy the computed groups to the group array
    group[suf[i]] = sorGroup[i];


    if (true) {  // For print
      for (int i = 0; i < n; i++) {
        print_suffix(suf[i], n);

        cout << "\t" << suf[i] << "\n";
      }
      cout << "\n";
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif

  cin >> str; // aaabaca
  buildSuffixArray();

  return 0;
}
