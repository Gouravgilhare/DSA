#include<iostream>
using namespace std;
 
 
 
int main()
{
    
    int size = 10;
    int arr[size] = {45, 12, 65, 32, 12, 23, 74, 64, 16,85};
    int i=0,j;
    while( i<size){
        int temp= arr[i];
        j= i-1;
        while(j>=0 && arr[j]>temp){ //running backward
            arr[j+1]= arr[j]; //swapping elements to right unit ith position
            j--;
        }
        arr[j+1] = temp;  // at this j == -1 -> -1+1 = 0 arr[0] = temp;
        i++;
    }


    for(int k = 0 ;k<size; k++){
        cout<< arr[k]<<" ";
    }
return 0;
}