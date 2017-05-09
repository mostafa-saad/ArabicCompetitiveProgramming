// Suffix array algorithms (nlognlog and nlogn) are from my coach Mohamed Abd Wahab, aka Fegla

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

//#define N_LOGN_LOGN
#ifdef N_LOGN_LOGN

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
  }
}

#endif

#define N_LOGN
#ifdef N_LOGN

////////////////////////////////////////////////////
////////////////////////////////////////////////////

const int MAXLENGTH = 2 * 100 * 1000 + 9;
char str[MAXLENGTH + 1];  //the string we are building its suffix array
int suf[MAXLENGTH + 1];  // the sorted array of suffix indices
int group[MAXLENGTH + 1];  //In ith iteration: what is the group of the suffix index
int sorGroup[MAXLENGTH + 1 < 128 ? 128 : MAXLENGTH + 1];  //temp array to build grouping of ith iteration

int groupStart[MAXLENGTH + 1];  //the start index in the sorted array of the current group
int newSuf[MAXLENGTH + 1];  //temp array to store in it the new sorted array
int n;  //number of suffixes

void print_suffix(int suf_pos) {
  for (int j = suf_pos; j < n - 1; ++j)  // n-1 is string length NOT n
    cout << str[j];
}

void buildSuffixArray() {

  n = 0;
  memset(sorGroup, -1, (sizeof sorGroup[0]) * 128);

  //bucket sort on the first char of suffix
  for (n = 0; n - 1 < 0 || str[n - 1]; n++)
    //treat sorGroup as head of linked list and newSuf as next
    newSuf[n] = sorGroup[str[n]], sorGroup[str[n]] = n;

  int numGroup = -1, j = 0;
  for (int i = 0; i < 128; i++) {
    //compute the groups and groupStart and starting suf
    if (sorGroup[i] != -1) {
      groupStart[++numGroup] = j;
      int cur = sorGroup[i];  // cur = head

      while (cur != -1) {
        suf[j++] = cur;
        group[cur] = numGroup;
        cur = newSuf[cur];  // cur->next
      }
    }
  }

  sorGroup[0] = sorGroup[n - 1] = 0;  //assume that the first group index 0 for next iteration;
  newSuf[0] = suf[0];  //put the empty suffix to be the smallest suffix

  //loop until the number of groups=number of suffixes
  for (int h = 1; sorGroup[n - 1] != n - 1; h <<= 1) {
    if (false) {  // For print
      for (int i = 0; i < n; i++) {
        print_suffix(suf[i]);

        cout << "\t" << suf[i] << "\t" << group[suf[i]] << "\t" << groupStart[group[suf[i]]] << "\n";
      }
      cout << "\n";
    }
    for (int i = 0; i < n; i++) {  //sort using 2h in the array newSuf
      int j = suf[i] - h;
      if (j < 0)
        continue;
      newSuf[groupStart[group[j]]++] = j;
    }
    for (int i = 1; i < n; i++) {  //compute the 2h group data given h group data
      bool newgroup = group[newSuf[i - 1]] < group[newSuf[i]] || (group[newSuf[i - 1]] == group[newSuf[i]] && group[newSuf[i - 1] + h] < group[newSuf[i] + h]);

      sorGroup[i] = sorGroup[i - 1] + newgroup;
      if (newgroup)
        groupStart[sorGroup[i]] = i;
    }
    for (int i = 0; i < n; i++) {  //copy the data
      suf[i] = newSuf[i];
      group[suf[i]] = sorGroup[i];
    }
  }
}

#endif

int Rank[MAXLENGTH + 1];
int lcp[MAXLENGTH + 1];

void buildLcp() {
  //compute the rank of each suffix
  for (int i = 0; i - 1 < 0 || str[i - 1]; i++)
    Rank[suf[i]] = i;

  int c = 0;  // the length of lcp between i and j
  for (int i = 0; i - 1 < 0 || str[i - 1]; i++) {
    if (Rank[i]) {  //if i is not the first suffix in the sorted array
      int j = suf[Rank[i] - 1];  //find the element before i and name it j
      while (str[i + c] == str[j + c])
        c++;  //count the number of shared chars
    }
    lcp[Rank[i]] = c;  //store the result in lcp array
    if (c)
      c--;  //Decrement c by one because length of lcp of i+1 is c-1
  }
  if (false) {
    for (int i = 0; i < n; i++) {
      print_suffix(suf[i]);
      cout << "\t" << suf[i] << "\t" << Rank[i] << "\t" << lcp[i] << "\n";
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
char pat[MAXLENGTH + 1];

void find_patterns_queries() {
  cin >> str;
  buildSuffixArray();
  cout << "\n**************************************\n\n";

  start_again:
  // Src: http://www.geeksforgeeks.org/suffix-array-set-1-introduction/
  while (cin >> pat) {  // O(mLogn)
    int m = strlen(pat);  // get length of pattern, needed for strncmp()

    int l = 0, r = n - 1;
    while (l <= r) {
      // See if 'pat' is prefix of middle suffix in suffix array
      int mid = l + (r - l) / 2;
      int res = strncmp(pat, str + suf[mid], m);

      if (res == 0) {
        cout << "Pattern found at suffix: [";
        print_suffix(suf[mid]);
        cout << "]\n";
        goto start_again;
      }
      // Move to left or right based on string comparison results
      if (res < 0)
        r = mid - 1;
      else
        l = mid + 1;
    }
    // We reach here if return statement in loop is not executed
    cout << "Pattern not found\n";
  }
  exit(0);
}

void smallest_lexicographically() {
  cin >> str;
  int n = strlen(str);

  for (int i = 0; i < n; ++i)  // Concatenate
    str[i + n] = str[i];
  str[2 * n] = 0;

  buildSuffixArray();
  buildLcp();

  // cases: aa is tricky. Fail if used <= n NOT <= 2*n
    // Ass the first string suffixes are all in 2nd part of array
  for (int i = 0; i <= 2*n; ++i) {
    if (suf[i] < n) { // from suffixes of 1st string
      while (lcp[i + 1] >= n)
        ++i;  // last one of common prefix will have smallest index
      cout << suf[i] << "\n";
      break;
    }
  }

  /*
  int lexi_tie_first = -1;
  for (int i = 0; i <= 2*n; ++i) {
    if (suf[i] >= n) {
      if (lexi_tie_first == -1)
        continue;  // from 2nd concatenated string
      else
        break;
    }
    if (lexi_tie_first == -1)
      lexi_tie_first = suf[i];  // we found 1
    else if (lcp[i] >= n)  // another one of our n letters
      lexi_tie_first = min(lexi_tie_first, suf[i]);  // we found 1
    else
      break;  // we have already the smallest one
  }
  cout << lexi_tie_first << "\n";
  */
}

//Modification of Lyndon decomposition: The concatenation will have in between one of si
//that is less than reminder
int min_cyclic_shift(string s) {
  s += s;
  int n = sz(s), i = 0, ans = 0;
  while (i < n / 2) {
    ans = i;
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        ++k;
      ++j;
    }
    while (i <= k)
      i += j - k;
  }
  //solution is in s.substr (ans, n/2)
  return ans;  //0-based idx of position where rotating string cause it lexico
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.txt", "rt", stdin);
#endif

  smallest_lexicographically();

  return 0;
}
