//QUESTION  : 4
//REVERSE THE ARRAY

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  
int main()
{

    int arr[] = {45,61,79,81,1,32,16};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"array Before reversing : "<<endl;
    for(int i = 0; i< n; i++ ) cout<<arr[i]<<" ";


    for(int i = 0; i< n/2; i++ ){

        arr[i] += arr[n-i-1];
        arr[n-i-1] =  arr[i] - arr[n-i-1];
        arr[i] =  arr[i] - arr[n-i-1];
    }
    cout<<"\narray After reversing : "<<endl;
    for(int i = 0; i< n; i++ ) cout<<arr[i]<<" " ;


return 0;
}