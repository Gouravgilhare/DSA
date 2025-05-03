#include<iostream>
using namespace std;
 
struct Node {
    int data;
    struct  Node * left;
    struct  Node * right;
    Node(int data){
        this->data= data;
        left= nullptr;
        right= nullptr;
    }
};



int inorder( struct Node *root, int count){
    if(root == nullptr) return count;
    count++;
    inorder(root->left,count);
    cout<<root->data;
    inorder(root->right,count);

}
int main()

{
    struct Node*  root= new struct Node(); 
    root->data= 10;
    root->left->data = 11;
    root->right->data = 12;
    root->right->left->data = 15;
    root->left->left->data = 13;
    root->left->right->data= 14;

    int count =0;
    cout<<inorder(root,count);

return 0;
}