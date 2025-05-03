#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
// You are given an integer array arr. You can choose at most one element to delete. Your task is to find the maximum possible sum of a non-empty subarray after deleting at most one element.
// A subarray is a contiguous part of an array.
 
 
int main()
{
    vector<int> arr1={ -1 ,2,6,-5,4};

    int n = 5;
    //GENERATING RANDOM ARRAY
    // cout<<"Enter size of arr : ";
    // cin >> n;
    
   
    sort(arr1.begin(),arr1.end());
    for(int  i=0 ; i< n;i++)
    cout<<arr1[i]<<" ";
    int start=0,end=0;
    int maxi=INT_MIN;
    int sum =0;
    for(int i =0 ;i<n; i++)
    {  
        sum += arr1[i];
        end = i;
        maxi= max(maxi, sum);

        if(sum<0) {
            sum = 0;
            start=i+1; 
        }
    }
    int mini =INT_MAX; int minIndex;
    cout<<"\nSubarray : \n";

    for(int i=start-1; i<= end;i++){
        cout<< arr1[i]<<" ";
        if( mini > arr1[i]){
            mini = arr1[i];
            minIndex= i;
        }
    }
    cout<< "\nMaxsum before : "<<maxi;
    cout<<"\nremoving : "<<arr1[minIndex];
    cout<< "\nMaxsum : "<<(arr1[minIndex] <0)?maxi-arr1[minIndex]:maxi+arr1[minIndex];
    

return 0;
}