// QUESTION : 7 
// FIND MISSING NUMBER FROM GIVEN  ARRAY

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
 
int main()
{

    int arr[]= {7, 1, 9, 3, 6, 8, 10, 2, 5,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int xorSum =0;
    // xor addition with full range [0-n]
    for(int i =0 ; i<= n ; i++){
        xorSum = xorSum^i;
    }
    // xor addition with array
    for(auto a  :  arr){
        xorSum = xorSum^a;
    }


    cout << xorSum;
    
return 0;
}


//OUTPUR : 4