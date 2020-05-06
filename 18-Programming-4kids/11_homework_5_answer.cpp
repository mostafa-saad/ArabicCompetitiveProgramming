// By Basel Bairkdar: https://www.facebook.com/baselbairkdar
#include<iostream>
using namespace std;

int main()
{
    int ans=0;
    string str;

    cin >> str;
    /**
        how to convert str to int ?
        say we have a string "123"
        now, make ans=1 which is the first character of str
        the second character is 2
        we need to put 2 in the ans properly (so we get ans=12 for now)
        simply, if we multiply ans by 10
        ans*=10 => ans=10
        then add 2 => ans+=2 => ans=12
        repeat same process for every character
    **/
    for (int i=0;i<str.size();i++)
    {
        ans*=10;// when i=0 ans is 0 too, so ans*=10 keeps ans=0

        ans+=str[i]-'0';/** when i=0 ans will be the first character of str **/
    }
    cout << ans << " " << ans*3 << endl;
    return 0;
}
