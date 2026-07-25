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
    int helper(TreeNode*root, int len){
        if(!root) return len;

        if(!root->left && !root->right){
            return len+1;
        }

        if(!root->right)
        return helper(root->left, len+1);
        
        if(!root->left)
        return helper(root->right, len+1);


        return min(helper(root->left, len+1), helper(root->right, len+1));
    }
    int minDepth(TreeNode* root) {

        return helper(root,0);
    }
};