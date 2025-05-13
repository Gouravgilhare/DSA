#include<iostream>
using namespace std;
 
 class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data= data;
        left= nullptr;
        right=nullptr;
    }
 };
 
 int inorder( struct Node *root, int count){
    if(root == nullptr) return count;
    count++;
    inorder(root->left,count);
    cout<<root->data;
    inorder(root->right,count);

}

 void insert(Node *root, int data){
    if(root == nullptr) 
    {

        root = new Node(data);
        return;   
    } 

    if(data >= root->data){
        insert( root->right, data);
    }else if(data < root->data){
        insert(root->left ,data);
    }
 }
int main()
{   
    Node*root=nullptr;
    int size ;
    cin >> size;
    for(int i=1; i<=size;i++ ){
        int data;
        cin >> data;
        insert(root, data);
    }
    int count=0;

    inorder(root,count);
    

return 0;
}