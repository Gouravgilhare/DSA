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
    int helper(TreeNode *root, int currSum){

     if(!root) return 0;
    
    currSum = currSum * 10 + root->val;
    
    if(!root->left && !root->right){
        return currSum;
    }
     int left = helper(root->left, currSum);
     int right = helper(root->right,currSum);

     return left + right;
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return -1;

        return helper(root,0);
    }
};