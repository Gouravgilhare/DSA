class Solution {
public:
    int n;

    int solve(vector<int>&nums, int i, int p,vector<vector<int>>&dp){
        if(i >= n) return 0;
        int take = 0, notTake;


        if( dp[i][p+1]!=-1) return dp[i][p+1];

        if(p==-1 || nums[p]<nums[i]){
            take = 1 + solve(nums, i+1, i, dp);
        }
            notTake =  solve(nums,i+1, p,dp);
        


        return dp[i][p+1] = max(take, notTake);

    }


    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));


        return solve(nums, 0, -1,dp);


    }
};