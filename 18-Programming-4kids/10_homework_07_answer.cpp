// By Amr Fahim https://www.facebook.com/amrfahim2020
// Homework 7 solution 
#include <iostream>
using namespace std ;

// We use 2 frequency arrays one for the positive numbers and the other for the negative 

int n , neg_num[500 +10] , pos_num[270 + 10 ]  , max_num , max_freq ;

int main()
 {
    cin >> n ;
    int arr[n] ;
    
    for (int i = 0 ; i < n ;i++ )
    {
         cin >> arr[i] ; 
         // Check the sign of the input value 
         //to know which array we should add the deal with
         if (arr[i] >= 0 ) 
         {
             pos_num[arr[i]]++ ;

         // Comparing the value we have now with the max value  
            if (pos_num[arr[i]] > max_freq ) 
            {
                max_freq = pos_num[arr[i]] ;
                max_num = arr[i] ;
                
            }  

         }
         else if (arr[i] < 0 ) 
         {
             neg_num[arr[i]]++ ;

              // Comparing the value we have now with the max value  
            if (neg_num[arr[i]] > max_freq )
            {
                max_freq = neg_num[arr[i]] ;
                max_num = arr[i] ;
            }
    }

    
}
    cout << max_num <<" has repeated " << max_freq <<" times " ;
}
