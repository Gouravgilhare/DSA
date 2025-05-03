//BINARYSEARCH RECURSIVELY

#include<iostream>
using namespace std;
 
 int binarySearch( int *arr, int ele, int beg, int last){
     
     if( beg >last) return -1;

    int mid = (beg+last)/2;


    if(arr[mid] == ele) return mid;
        if( ele > arr[mid]) return binarySearch(arr, ele, mid+1,last);
        else return binarySearch(arr, ele, beg, mid-1); 
 }
 
int main()
{
int arr[10]={12, 24, 35, 41, 52, 63, 74, 85, 91, 99};
int ele = 74;
cout<<"Element "<<ele<<" is at " <<binarySearch(arr,ele,0,9)<<" index"; 


return 0;
}

//Element 74 is at 6 index