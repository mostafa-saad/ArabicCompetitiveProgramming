#include<iostream>
#include<cstdio>
using namespace std;

// Solves computes number of ways to cross out characters in a string
// so that the remaining characters form a palindrome.

// This programme uses dynamic programming.  Some tried to solve the
// problem by brute force, but their programmes ran for too long, in
// spite of the fact that the longest input word was only 19 characters.

long long A[1001][1001];  
// For i<=j, A[i,j] will hold the number of palindromes
// that can be formed from the substring a[i..j] by
// crossing out some characters
long long B[1001][1001]; 
// For i<=j, B[i,j] will hold the number of palindromes
// that can be formed from the substring a[i..j] by
// crossing out some characters, not including a[i].
// (i.e. not allowed to cross out a[i])

// Note:  for the above definition, I count the empty string as a 
// palindrome.  However, the problem says the empty string is not a
// palindrome, so when I output the answer in the last line of the big 
// loop, I subtract 1 from A[0,m-1].

int main() 
{
	long long n;
	char a[100];
	
	cin>>n;
	
	for (int ix = 1; ix <= n; ix++)
	{
		cin>>a;
		
		int m=strlen(a);
		
		for (int j=0; j<m; j++)
		{
			A[j][j]=2;
			B[j][j]=1;
		}
		
		for (int len=2; len <= m; len++)
		{
			for (int i = 0; i<=m-len; i++)
			{
				int j=i+len-1;
				
				if (a[i] == a[j] && i+1 <= j-1) 
				{
					A[i][j] = A[i+1][j] + B[i][j-1] + A[i+1][j-1];
					
					// First term is the number of ways to get a palindrome by
					// crossing out the first character.
					
					// Second term is the number of ways to get a palindrome by
					// crossing out the last character (but not the first).
					
					// Third term is the number of ways to get a palindrome by
					// not crossing out either the first or last character.
					
					B[i][j] = B[i][j-1] + A[i+1][j-1];
				}
				else if (a[i] == a[j])
				{
					// this is just a special case when j = i+1
					// because A[i+1][j-1] is not defined in this case.
					// this come from base case intialization
					A[i][j] = A[i+1][j] + B[i][j-1] + 1;
					B[i][j] = B[i][j-1] + 1;
				}
				else 
				{
					A[i][j] = A[i+1][j] + B[i][j-1];
					B[i][j] = B[i][j-1];
				}
			}
		}
		cout << A[0][m-1]-1 << "\n";
	}
	return 0;
}