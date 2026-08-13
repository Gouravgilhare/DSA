class Solution {
public:
    int helper(int n, vector<int>&nums, vector<int>& dp){
        if(n >= nums.size()) return 0;
        if(dp[n] != -1) return dp[n];

        int take2 = nums[n] +    helper(n+2,nums,dp );
        int nottake = helper ( n+1, nums,dp);  
        return dp[n] = max(  take2, nottake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1 , -1);

        return max(helper(0, nums,dp), helper(1, nums, dp));
    }
};