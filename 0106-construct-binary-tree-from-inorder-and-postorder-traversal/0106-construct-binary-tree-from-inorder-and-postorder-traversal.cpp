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
    TreeNode*helper(vector<int>&inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd, unordered_map<int, int>&mp){
        if(postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode * root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[root->val];
        int leftSize=  inRoot- inStart;
        root->left = helper(inorder,inStart ,inRoot-1 , postorder,postStart,postStart + leftSize-1 , mp);
        root->right = helper(inorder,inRoot+1 ,inEnd , postorder,postStart+leftSize ,postEnd-1 , mp);


        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // left root right
        // left right root
        int n = inorder.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]]= i;
        }

        return helper( inorder, 0,n-1,  postorder, 0, n-1, mp);



    }
};