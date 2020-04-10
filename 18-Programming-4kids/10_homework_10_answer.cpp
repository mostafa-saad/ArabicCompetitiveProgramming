// By Amr Fahim https://www.facebook.com/amrfahim2020
// Homework 10 solution

#include <iostream>
using namespace std ;

const int N = 2e5+10 ;
int n , arr[N] , k , min_index , max_index , max_sum = -1e9 ;

int main()
{
    cin >> k >> n ;
    // Note that we deal with 1-base array
    for (int i = 1 ; i <= n ; i++ )
    {
        cin >> arr[i] ;

        // Cumulative sum for the array to get sum of subarray without nested loop
        // Each element of the array carries the sum of all previous elements
        arr[i] += arr[i-1] ;
    }    

    for (int i = k ; i <= n ; i++){
        if (arr[i] - arr[i-k] > max_sum )
        {
            max_sum = arr[i] - arr[i-k] ;
            min_index = i-k+1;
            max_index = i ;

        }
    }
    cout << "Sum is " << max_sum << endl << "The indices are " ;
    while ( min_index <= max_index )
    {
        // The -1 here to print 0-base index 
        cout << min_index -1 << ' ' ;
        min_index++ ; 
    }
    
}

