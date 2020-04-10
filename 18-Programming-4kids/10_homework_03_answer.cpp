// By Basel Bairkdar https://www.facebook.com/baselbairkdar

#include<bits/stdc++.h>

using namespace std;

const int N=205;

int n,a[N],mn=1e9,mx=-1,index_mn,index_mx;

int main()
{
    /**
    store minimum value in mn, maximum value in mx
    store the index of mn in index_mn, index of mx in index_mx

    why initiating mn with large number and mx with small number ?
    try mn=0 and see what happens
    **/
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        if (a[i]<mn)
        {
            mn=a[i];
            index_mn=i;
        }
        if (a[i]>mx)
        {
            mx=a[i];
            index_mx=i;
        }
    }
    a[index_mn]=mx;
    a[index_mx]=mn;
    for (int i=0;i<n;i++)
    {
        cout << a[i] << ((i==n-1)?"\n":" ");
    }
    return 0;
}
