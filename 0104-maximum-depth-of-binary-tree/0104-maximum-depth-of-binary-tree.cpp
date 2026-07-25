/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findLen(TreeNode * root , int len){
        if(root== nullptr) return len;
        return max(findLen(root->left, len+1),
         findLen(root->right ,len+1)); 

        
    }
    int maxDepth(TreeNode* root) {
        
        
        return findLen(root, 0);
    }
};