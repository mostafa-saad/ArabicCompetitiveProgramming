#include<iostream>
#include<cstdio>
using namespace std;

long long A[61][61];  
/*
 * For i<=j, A[i,j] will hold the number of palindromes
 * that can be formed from the substring a[i..j] by
 * crossing out some characters, considering empty as pal
 */

int main() 
{
	int  n;
	char a[100];
	
	cin>>n;
	
	while(n--)
	{
		cin>>a;
		
		int m=strlen(a);
		
		for (int j=0; j<m; j++)
			A[j][j] = 2;	/* 1 for char, 1 for empty string */
		
		for (int len=2; len <= m; len++)
		{
			for (int i = 0; i<=m-len; i++)
			{
				int j=i+len-1;

				if(j == i+1)	/* Undefined in base case */
				{
					if (a[i] == a[j])
						A[i][j] = 4;						   /* Like aa */
					else
						A[i][j] = 3;						   /* Like ab */
				}
				else if (a[i] == a[j])
					A[i][j] = A[i+1][j]+A[i][j-1];			   /* Like aba */
				else 
					A[i][j] = A[i+1][j]+A[i][j-1]-A[i+1][j-1]; /* Like abc */
			}
		}
		cout << A[0][m-1]-1 << "\n";	/* -1 For removing empty */
	}
	return 0;
}