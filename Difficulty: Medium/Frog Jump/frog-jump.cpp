class Solution {
  public:
    
    int helper(vector<int>& height, int i,vector<int>&dp) {
        if(i==0) return 0;
        // if(i==1) return 1;
        if(dp[i]!=INT_MAX) return dp[i];
        
        int left  = helper(height, i-1, dp) + abs(height[i] - height[i-1]);
        
        int  right  = INT_MAX;
        if(i>1)
         right  = helper(height, i-2, dp) + abs(height[i] - height[i-2]);
    
        dp[i] = min(left, right);
        return dp[i];
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,INT_MAX);
        return helper(height, n-1,dp);
        
    }
};