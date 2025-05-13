
// count swaps required to sort an array using insertion sort



#include<iostream>
#include<vector>
using namespace std;
 #define size 10
 
 void display(vector<int>&arr){
    for(int i = 0 ; i<size; i++){
        cout<<arr[i]<<" ";
    }
 }
 
int main()
{
    vector<int> arr(10,0);
    cout<<"BEFORE : "<<endl;
    for(int i =0 ; i<size; i++){
        arr[i] = abs(rand()%90+10);
        cout<<arr[i]<<" ";
    }
    
    int count= 0 ;
    //insertion Sort
    for(int i =0 ; i<size-1;i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0  && temp < arr[j]){
            swap(arr[j],arr[j+1]);
            count++;
            j--;
        }
        arr[j+1] = temp; 

    }


    cout<<"\nAFTER : "<<endl;
    display(arr);


    cout<<"\nNo. Of swaps : "<<count;

return 0;
}