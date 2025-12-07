class Solution {
  public:
  
    int minimumCoins(vector<int>&coins, int target, int index , vector<vector<int>>&dp){
        if(index == 0 ){
            if(target%coins[0] == 0) return target/coins[0];
            return 1e9;
        }
        if(target == 0) return 0;
        
        // int sameCoin = 1e9;
        // if(target >= coins[index])
        // sameCoin  = 1 + minimumCoins(coins, targe    t-coins[index], index);
        if(dp[index][target]!= -1) return dp[index][target];
        int take = 1e9;
        if(target >= coins[index])
        take  = 1 + minimumCoins(coins, target-coins[index], index,dp);
        int notTake  = minimumCoins(coins, target, index-1,dp);
        
        return dp[index][target] = min(take, notTake);
        
    }
    int findMin(int target) {
        // code here
        vector<int>coins ={1,2,5,10};
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        
        int ans =  minimumCoins(coins, target, n-1,dp);
        
        if(ans >= 1e9) return -1;
        
        return ans;
         
    }
};