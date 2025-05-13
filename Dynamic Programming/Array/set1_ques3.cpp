#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
 
int main()
{

    vector<int> arr1;

    int n;
    //GENERATING RANDOM ARRAY
    cout<<"Enter size of arr : ";
    cin >> n;
    
    for(int i =0 ;i<n; i++){
        arr1.push_back(rand() % 90 + 10);
    }
    sort(arr1.begin(),arr1.end());
    for(int  i=0 ; i< n;i++)
    cout<<arr1[i]<<" ";


    if(n % 2 == 0){
        cout<<"\n meedian: \n";
        cout<<(float)(arr1[n/2-1]+arr1[n/2 ])/2;
    }
    else{
        cout <<" Middle Element : ";
        cout<<(float)arr1[n/2];
    }

    
return 0;
}