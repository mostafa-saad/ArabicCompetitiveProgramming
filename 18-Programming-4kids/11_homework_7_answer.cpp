// By Mohamed Yasser https://www.facebook.com/SanfourRadwan

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    cin >> input;
    int len = input.size() , cnt = 1;
    for(int i = 1 ; i < len ; i++){
        /**
            if the current character is equal previous character
            then they are in same group and we need increment count by 1

            otherwise they are in Different groups and we need print last group
            and start count 1
        */
        if(input[i-1] != input[i]){
            cout << input[i-1] << cnt << "_";
            cnt = 1;
        }else cnt++;
    }
    /// print last group
    cout << input[len-1] << cnt << "\n";
    return 0;
}
