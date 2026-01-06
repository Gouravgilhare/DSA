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


    int helper(TreeNode* root ){
        
        if(!root) return 0;
        queue<TreeNode*> q;
        int level = 0;
        int answerlevel = 1;
        int maxSum  = INT_MIN;
        q.push(root);
        int ans = 0;
            int currSum = 0;
        while(!q.empty()){

            int size = q.size();
            currSum = 0;
            level++;
            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                currSum += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
           
            if(currSum > maxSum ) 
            {
                maxSum = currSum;
                answerlevel = level;
            }
        }


        return answerlevel;
    }
    int maxLevelSum(TreeNode* root) {
            return helper(root);
            
    }   
};