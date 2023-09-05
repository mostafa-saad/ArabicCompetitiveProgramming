#include <iostream>

using namespace std;

int main()
{
    string big_str, small_str;
    cin>>big_str>>small_str;
    bool flag = 0;
    int big_size = (int)big_str.size();
    int small_size = (int)small_str.size();

    if (small_size > big_size) {
		cout << "NO\n";
		return 0;
	}

    for(int i = 0, j = 0; i < big_size; i++){
        if(big_str[i] != small_str[j++]){
            j = 0;
        }

        if(j == small_size)flag = 1;
    }

    if(flag)cout << "YES\n";
    else cout << "NO\n";
}
