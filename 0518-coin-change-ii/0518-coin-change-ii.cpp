class Solution {
public:
    int f(int target, vector<int>& coins, int index,vector<vector<int>>&dp){
        int  n  = coins.size();
        if(index == 0){
            if(target%coins[0]==0) return 1;
            else return 0;
        }

        if(target == 0) return 1;

        if(dp[index][target]!= -1) return dp[index][target];
        int notTake = f(target, coins, index-1,dp);
        int take  =  0;
        if(coins[index]<= target)
        take = f(target-coins[index],coins, index,dp);

        return dp[index][target] = take+ notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1, -1));
        return f(amount, coins, coins.size()-1,dp);
    }
};