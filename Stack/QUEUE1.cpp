#include<iostream>

#include<vector>

using namespace std;

int main(){

    int testcase;
    cin >> testcase;
    
    while(testcase--){
        int size, k;
        cin>>size;
        cin>>k;

        vector<int>q(size,0);
        int front=-1;
        int rear =-1;
        for(int i= 0 ;i<size;i++)
        {
            if(front==-1){
                front=0;
            }    
            rear++;
            cin>> q[rear];
        }
        int arr[k],temp[size-k];
        for(int i = 0; i<k;i++){
            arr[i]=q[front];
            front++;
          
        }
        int j=0;
        
        while(front<= rear){
            temp[j]=q[front];
            front++;
            j++;
        }
        front=-1;rear=-1;
        int l=0;
        while(rear < size-k){
            if(front == -1) front++;
            rear++;
            q[rear]= temp[l];
            l++;
        
        }j=0;
       while(rear < size){
           
            q[rear] = arr[j];
            j++;
            rear++;
        }
        int i= front;
        while(i<size){
            cout<<q[i]<<" ";
            i++;
        }

        cout<<endl;
    }

    return 0;
}
