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
    bool leftToRight= true;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root )return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){

            int size = q.size();
            vector<int>temp(size);

            for(int i = 0 ; i< size; i++){

                TreeNode * curr = q.front();
                // temp.push_back(curr->val);
                q.pop();

                int index = leftToRight? i : size- i - 1;
                temp[index] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            ans.push_back(temp);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};