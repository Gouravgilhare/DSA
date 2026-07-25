class Solution {
public:
    bool helper(TreeNode* root, int targetSum) {
        if (!root) return false;

        if (!root->left && !root->right)
            return targetSum == root->val;

        targetSum -= root->val;

        return helper(root->left, targetSum) ||
               helper(root->right, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum);
    }
};