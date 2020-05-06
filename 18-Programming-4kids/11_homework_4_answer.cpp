// By Basel Bairkdar: https://www.facebook.com/baselbairkdar
#include<iostream>
using namespace std;

string input,str;

int main()
{
    cin >> input >> str;

    int in=0;/** index of str **/

    for (int i=0;i<input.size();i++)
    {
        if (input[i]==str[in])/** if there is a match just increase the index **/
        {
            in++;
            if (in==str.size())break;/** reached the end of str **/
        }
    }


    if (in==str.size())/** have we reached the end of str ? if so then it is a subsequence **/
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
