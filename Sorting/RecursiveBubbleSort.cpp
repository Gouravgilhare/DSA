#include<iostream>
#include<algorithm>
#include<time.h>
#include<vector>
using namespace std;
 
 void bubbleSort(vector<int>&arr, int size){
     
    if( size == 1)return;
    
    int count  = 0;

    for(int i =0 ; i<size -1; i++){
        if(arr[i] > arr[i+1])
        swap( arr[i], arr[i+1]);
    }
   
 
    bubbleSort(arr, size-1);

   
 }
 
int main()
{
    vector<int> arr = { 12,98,32,45,12,7,13,74,21,42,89};
    int i= 0;int j=0;
    bubbleSort(arr, arr.size());
    for( auto a : arr)
    cout<< a << " ";

return 0;
}
