class Solution {
public:
    int helper(int n , vector<int>&cost,vector<int>&dp ){
        if(n >= cost.size()) return 0;
        if(dp[n]!= -1) return dp[n];
        int left =  cost[n] + helper(n+1 , cost, dp);
        int right = cost[n] + helper(n+2 , cost, dp);

        return dp[n] = min(left, right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, -1);
        return min(helper(0,cost, dp) , helper(1,cost, dp));
    }
};