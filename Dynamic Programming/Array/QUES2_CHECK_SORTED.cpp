#include<iostream>

using namespace std;

bool check_arr(int *arr, int n);
int main(){

    int arr[] = {46,6,1,67,79,431,13 ,64 };
    int n = sizeof(arr)/sizeof(arr[0]);

   bool ans = check_arr( arr, n);
    if(ans) cout<<  "ARRAY IS SORTED"<<endl;
    else cout<<"ARRAY IS UNSORTED";


    return 0;
}

bool check_arr(int *arr, int n){
    int i=0;
    for(i =1; i<n;i++){
        if( arr[i] < arr[i-1]) return false;
    }

    return true;
}