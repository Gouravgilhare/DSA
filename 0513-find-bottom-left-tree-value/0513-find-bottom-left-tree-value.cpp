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
    int ans = 0;
    int maxDepth = -1;
    void helper(TreeNode* root, int height){
        if(!root) return ;

        if(height > maxDepth ){
            maxDepth = height;
            ans = root->val;
        }


         helper(root->left, height+1);
        
         helper(root->right, height + 1 );

        // return (left > right)?left : right;

    }

    int findBottomLeftValue(TreeNode* root) {

        // if(!root->left ) return root->val;

        helper(root, 0);
        return  ans;
    }
};