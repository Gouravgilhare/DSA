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
    vector<int>ans; int cnt=0;
    void helper(TreeNode * a, int level ){
        if(!a) return;

        if(ans.size() == level )ans.push_back(a->val);

        helper(a->right, level+1);
        helper(a->left, level+1);

    }
    vector<int> rightSideView(TreeNode* root) {

        helper(root, 0);
        return ans;
    }
};