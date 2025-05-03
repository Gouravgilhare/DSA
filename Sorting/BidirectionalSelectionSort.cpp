// implement a sorting a algorithm that slightly improves on selection sort
//(cocktail Selection sort) ( Bidirectional sort)

#include<iostream>
#include<vector>
using namespace std;
 
 
 
int main()
{
    int size = 10;
    int arr[size] = {45, 12, 65, 32, 12, 23, 74, 64, 16,85};

    cout<<"BEFORE : "<<endl;
    for(int i =0 ; i<size; i++)
        cout<<arr[i]<<" ";

    //BIdirectional Selection Sort
    int left = 0 , right  = size-1;
    while(left<right){

        int minI = left;
        int maxI=right;
        for(int i = left; i<=right; i++){
            if(arr[i]< arr[minI])
                minI = i;
            if(arr[i]> arr[maxI])
                maxI = i;
        } 

        swap(arr[left] , arr[minI]);  

        if(maxI == left) maxI= minI;   //if max == left but the old value is swapped with min so that max =min;

        swap(arr[right], arr[maxI]);

        left++;
        right--;
    }



    cout<<"\nAFTER : "<<endl;
    for(int i =0 ; i<size; i++)
        cout<<arr[i]<<" ";
return 0;
}
