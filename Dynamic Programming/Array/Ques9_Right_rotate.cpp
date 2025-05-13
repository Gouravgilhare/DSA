#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
 
int main()
{

    int test;
    cin >> test;
    int arr[test];


    int i=0;
    while( i <test){
            cin >> arr[i];
            i++;
    }
    
    ReverseByK( arr, 3);
    // for(i =0 ; i<test; i++)
    // cout<<arr[i]<<" ";

    // int temp =arr[test-1] ;
    // for(int i=test-1; i> 0;i--){
    //     arr[i] = arr[i-1];

    // }
    // arr[0]= temp;


    // cout<< endl;

    // for(i =0 ; i<test; i++)
    // cout<<arr[i]<<" ";

// return 0;
}
//reverse by k 

void ReverseByK ( int *arr, int k){
    
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< "Before : \n";
    display(arr);
    reverse( arr, k-1,0);
    reverse( arr,n-1,k);
    reverse( arr, n-1,0);
    cout<< "After : \n";
    display(arr);


}

void reverse(int *arr, int start, int end)
{
    while (start > end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void display(int * arr){
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i =0; i< n; i++)
        cout<< arr[i]<< " ";
}