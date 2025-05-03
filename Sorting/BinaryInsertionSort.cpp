#include<iostream>
#include<vector>
using namespace std;
 #define size 10
 


 int binarysearch(vector<int>&arr, int key, int start, int end){

    int n =size;
    while(start < end){
        int mid = (start+end)/2;

        if(arr[mid]< key){
            start = mid+1;
        }
        else end = mid;
    }

    return start;
 }
 
int main()
{
    vector<int> arr(10,0);
    cout<<"BEFORE : "<<endl;
    for(int i =0 ; i<size; i++){
        arr[i] = abs(rand()%90+10);
        cout<<arr[i]<<" ";
    }

    //binaryInsertionsor
    for (int   i = 0; i < size; i++)
    {

        int temp = arr[i];
        int pos= binarysearch(arr, temp, 0, i);

        for (int j = i; j >pos; j--)
        {
            arr[j] = arr[j-1];
        }

        arr[pos] = temp;
        

    }
    cout<<"\nAFTER : "<<endl;
    for(int i =0 ; i<size; i++){
   
        cout<<arr[i]<<" ";
    }

    

return 0;
}