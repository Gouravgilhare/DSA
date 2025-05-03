#include<iostream>
#include<algorithm>
using namespace std;
 
 
 
int main()
{
    int size = 10;
    int arr[size] = {45, 12, 65, 32, 12, 23, 74, 64, 16,85};


//minMethod
    for(int i = 0 ; i<size-1; i++){
        int temp=i;
        for(int j = i+1; j<size; j++){
            if(arr[temp] > arr[j])
              temp = j;
        }
        swap(arr[temp], arr[i]);
    }



    for(int i =0 ; i<size; i++)
        cout<<arr[i]<<" ";

return 0;
}