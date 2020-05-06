// By Basel Bairkdar: https://www.facebook.com/baselbairkdar
#include<iostream>
using namespace std;

string input,str;

int main()
{
    cin >> input >> str;
    bool is_substring=0; /** we will say that it's not a substring at the beginning **/


    int in=0;
    for (int i=0;i<input.size();i++)
    {
        if (input[i]==str[in])/** characters are equal (possible match) **/
        {
            in++; /** increase index **/
            if (in==str.size())
            {
                is_substring=1;
                break;/** found a solution, no need to stay in the loop **/
            }
        }
        else
        {
            /**
                if the characters are different and we have not broken
                the loop yet (no solution so far)
                make in=0 to look for possible match
            **/
            in=0;
        }
    }


    if (is_substring)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
