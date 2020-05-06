// By Mohamed Yasser https://www.facebook.com/SanfourRadwan
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    cin >> input;
    int len = input.size();
    /**
        we sure that first character in string
        is found in first group
    **/
    cout << input[0];
    for(int i = 1 ; i < len ; i++){
        /**
            if the current character is equal previous character
            then they are in same group
            otherwise they are in Different groups
        */
        if(input[i-1] != input[i])/// print space between the different groups
            cout << ' ';
        cout << input[i];
    }
    return 0;
}
