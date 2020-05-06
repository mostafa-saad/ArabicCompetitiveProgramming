// By Basel Bairkdar: https://www.facebook.com/baselbairkdar
#include<iostream>
using namespace std;

string input,str;

int main()
{
    cin >> input >> str;
    bool is_prefix=1; /** we will say that it's prefix at the beginning **/
    int n=str.size();
    /**
        check if str is eqaul
        to the first n letter of input
    **/
    for (int i=0;i<n;i++)
    {
        if (input[i]!=str[i])
        {
            is_prefix=0;
            break;
        }
    }
    if (is_prefix)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
