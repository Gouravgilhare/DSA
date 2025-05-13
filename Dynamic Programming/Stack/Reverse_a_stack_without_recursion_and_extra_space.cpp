#include<iostream>
#include<vector>
using namespace std;

struct st{
    int data;
    struct  st *top;
    st(int data){
        this->data= data;
        this->top = nullptr;
    }
};
struct st *top= nullptr;

void push( int data ){
    if( top== nullptr){
       top = new struct st(data);
        return;
    }
    struct st* newNode = new struct st(data);

    newNode->top  = top;
    top = newNode;
}



void reverse(){
    struct st *curr,*next,*prev;
    prev=curr= top;
    curr = curr->top;
    prev->top= nullptr;
    while( curr != nullptr){
        next= curr->top;
        curr->top= prev;
        prev = curr;
        curr= next;
    }
    top = prev;

} 
int main(){
  
    int size= 4;
    int data=0;
    for(int i=0; i<size; i++){
        cin >> data;
        push( data);
      
    }
    // reverse();
    struct st*temp =top;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp= temp->top;
    }
  
  
    return 0;
}
