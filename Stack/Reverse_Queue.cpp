#include <iostream>
#include<vector>
using namespace std;


int main(){

    vector<int> q(10);
    int size =10;
    int front =-1, rear = -1;
    int data;
    while(rear<size-1){
        if(front == -1)front++;
        rear++;
        cin>>data;
        q[rear]=data;
       
    }
    //stack
    vector<int> st(10);
    int top=-1;
    while(front<= rear){
        top++;
        st[top]= q[front];
        front++;
    }
    front=-1;
    rear = -1;
    while(top>-1){
        if(front == -1) front++;
        rear++;
        q[rear] = st[top];
        top--;
    }
    int k= front;
    while(k<=rear){
        cout<<q[k]<<" ";
        k++;
    }
    



    return 0;
}
