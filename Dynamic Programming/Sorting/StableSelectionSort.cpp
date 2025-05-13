// write a program for stable selection sort

#include<iostream>
#include<algorithm>
using namespace std;
 
 
 
int main()
{
    int size = 10;
    int arr[size] = {45, 12, 65, 32, 12, 23, 74, 64, 16,85};

    cout<<"BEFORE : "<<endl;
    for(int i =0 ; i<size; i++)
        cout<<arr[i]<<" ";

    //stable Selection Sort
    for(int i = 0 ; i<size-1;i++){

        int temp = i;    //if there is no min value it will store the same value in itself
        for(int j= i+1; j<size; j++){
            if(arr[temp] > arr[j])
            temp = j;   //finding the minvalue
        }

        int key = arr[temp]; //storing the min value
        while(temp > i){
            arr[temp]= arr[temp-1];     
            temp--;        //right shifting the values
        }
        arr[i]= key;    // storing the min value at  its position 

    }



    cout<<"\nAFTER : "<<endl;
    for(int i =0 ; i<size; i++)
        cout<<arr[i]<<" ";

return 0;
}