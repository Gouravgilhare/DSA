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
    bool helper(TreeNode* root, int k, unordered_set<int>&set) {
        if(!root) return false;
        TreeNode*temp = root;

        if(set.count(k-temp->val)){
            return true;
        }

        set.insert(temp->val);


        return helper(temp->left,k , set) || helper(temp->right, k , set);
        
        

    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>set;
        return helper(root, k, set);
    }
};