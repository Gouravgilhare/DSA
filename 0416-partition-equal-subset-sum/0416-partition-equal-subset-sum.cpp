class Solution {
public:

    bool helper(vector<int>& nums, int i , int target, int curr,     vector<vector<int>>&dp) {
        int n = nums.size();
        if(i == n || curr > target) return false;
        if(target == curr) return true;

        if(dp[i][curr]!= -1) return dp[i][curr];
        bool take = helper(nums, i+1, target, curr+nums[i],dp);
        bool nottake = helper(nums, i+1, target, curr,dp);

        return dp[i][curr] =  take || nottake;

    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0); 
        int target= totalSum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1, -1));
        // dp[0][0]=0;
        if(totalSum%2 ==  1){
            return false;
        }
        return helper(nums, 0, target ,0 ,dp);

    }
};