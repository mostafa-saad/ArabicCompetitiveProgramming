// By Basel Bairkdar: https://www.facebook.com/baselbairkdar
#include<iostream>
using namespace std;

string input,str;

int main()
{
    cin >> input >> str;
    bool is_suffix=1; /** we will say that it's suffix at the beginning **/
    int n=str.size();
    /**
        check if str is equal
        to the last n letter of input
    **/
    int in=0; /** index of str **/
    for (int i=input.size()-n;i<input.size();i++)
    {
        if (input[i]==str[in])/** careful, str[in] not str[i] **/
        {
            in++;
        }
        else if (input[i]!=str[in])/** careful, str[in] not str[i] **/
        {
            is_suffix=0;
            break;
        }
    }
    if (is_suffix)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
