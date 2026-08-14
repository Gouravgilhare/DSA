class Solution {
public:
    int helper(int n , int start, vector<int>&nums, vector<int>&dp){
        if(n > start ) return 0;
        if(dp[n] != -1  )return dp[n];

        int notTake =  helper( n +1, start , nums, dp);
        int take  = nums[n] + helper(n +2 , start, nums, dp);

        return dp[n] = max( take , notTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>dp(nums.size()  , -1);
        vector<int>dp2(nums.size() , -1);
        return max( helper(0, nums.size() -2  , nums, dp),  helper(1,nums.size()-1,  nums, dp2));
    }
};