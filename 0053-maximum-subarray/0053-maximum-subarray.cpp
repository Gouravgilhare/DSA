class Solution {
public:
    int helper(int i , vector<int>&nums,vector<int>&dp){
        if(i >= nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];


        int take = nums[i] +  helper(i+1, nums,dp);
        int notTake = nums[i];

        return dp[i] = max(take, notTake);
    }   
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        int ans = INT_MIN;

        for(int i =0 ; i< n ; i++){
            ans = max(ans, helper(i , nums, dp));
        }
       return ans;

    }
};