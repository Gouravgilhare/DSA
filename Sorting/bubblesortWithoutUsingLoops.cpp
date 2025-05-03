#include<iostream>
#include<vector>
using namespace std;
 
 void bubbleWithoutLoop(vector<int>&arr,int i, int j){
        if(i == arr.size()-1) return; //base case to stop recursion

        if(j<arr.size()-i-1){ //condition for inner recursion

            if(arr[j]> arr[j+1]){  //condition for swapping
                swap(arr[j],arr[j+1]);  //swapping
            }
            bubbleWithoutLoop(arr,i,j+1); //inner recursion : incrementing  j and i is same
        }else 
        bubbleWithoutLoop(arr,i+1,0);  // outer recursion
 }
 

int main()
{

    vector<int> arr(10,0);
    cout<<"Before: "<<endl;
    for(int i=0;i<10;i++){
   
        arr[i]= abs(rand()%90 + 10); //generation random 2 digit number
        cout<<arr[i]<<" ";
    }   
        cout<<endl;

    bubbleWithoutLoop(arr,0,0);  //function calling

    cout<<"\nAfter"<<endl;
    for(auto a : arr)
        cout<<a<<" "; //printing

return 0;
}