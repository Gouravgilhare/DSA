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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map <int,int> inMap;
        for(int i =0 ;i<inorder.size(); i++)
            inMap[inorder[i]]=i;
       return  buildTree( inorder , 0, inorder.size()-1, postorder,0, postorder.size()-1, inMap);
    }
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
     vector<int>& postorder, int poStart, int poEnd, unordered_map<int,int> &inMap ){
        
        if( poStart > poEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode( postorder[poEnd]);
        int inRoot = inMap[root->val];
        int numLeft =  inRoot  - inStart ;

        root->left = buildTree( inorder, inStart, inRoot-1, postorder, poStart, numLeft+poStart -1,inMap ); 
        root->right = buildTree( inorder, inRoot+1,inEnd, postorder, poStart + numLeft, poEnd-1,inMap );

        return root; 
    }
};
