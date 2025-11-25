/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    int helper(Node*node){
         
        if(!node)return 0;
        
        int old = node->data;
        
        int left = helper(node->left);
        int right = helper(node->right);


        node->data  = left + right;
        
        
        return node->data + old;

    }

    
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        // Your code here
       helper(node);
    }
};