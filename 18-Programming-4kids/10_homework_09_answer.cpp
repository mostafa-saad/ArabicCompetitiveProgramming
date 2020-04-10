// By Amr Fahim https://www.facebook.com/amrfahim2020
// Homework 9 solution
#include <iostream>
using namespace std ;

const int N = 2e5+10 ;
int occurrence[N] , sequence[N] , indx ;

int main()
 {
    cin >> indx ;
    sequence[0] = 0 ;
    occurrence[0] = 1 ;

    for (int i = 1 ; i <= indx ;i++ )
    {
        int cur = sequence[i-1] - (i-1) -1  ;

        if (cur < 0 || occurrence[cur] )
        {
            cur = sequence[i-1] + (i-1) + 1 ;
        }
         sequence[i] = cur ;
         occurrence[cur] = 1 ;
     
    }
   
   cout << sequence[indx] ;
    
}


