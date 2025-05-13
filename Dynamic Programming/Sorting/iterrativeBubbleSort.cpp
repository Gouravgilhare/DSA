#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
 
 
int main()
{
    vector<int> arr = { 12,98,32,45,12,7,13,74,21,42,89};
    for(int i = 0 ; i<arr.size()-2  ; i++){
        for(int j=0 ; j<arr.size()-1; j++)
        if(arr[j] > arr[j+1])
        swap(arr[j],arr[j+1]);
        
    }
    
    for(int i= 0 ; i<arr.size(); i++){
        cout<< arr[i]<<" ";
    }

return 0;
}