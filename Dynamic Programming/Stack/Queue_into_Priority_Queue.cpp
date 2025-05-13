#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
   vector<int>arr(6);
    int front=-1, rear=-1;
    while(rear<6){
        if(front == -1) front++;
        rear++;
        cin >> arr[rear];
    }

    sort(arr.begin(),arr.end());
    reverse(arr.begin(), arr.end());
    int i = front;
    while(i<rear){
        cout<<arr[i]<<" ";
        i++;
    }



    return 0;
}
