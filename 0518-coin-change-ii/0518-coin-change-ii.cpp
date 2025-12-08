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
        int n = coins.size();
        // vector<vector<long long>>dp(coins.size(),vector<long long>(amount+1, 0));
        using int128 = __int128_t;
        vector<int128>prev(amount+1, 0), curr(amount+1, 0);

        for(int i = 0 ; i<= amount; i++){
            prev[i] = (i%coins[0]==0);
        }



        for(int i = 1; i<n; i++){
            for(int j= 0; j<= amount; j++){
                
                int128 notTake = prev[j];
                int128 take = 0;
                if(coins[i]<=j) 
                take = curr[j-coins[i]];

                curr[j]= (long long)take+notTake;
            }

            prev = curr;
        }

        return prev[amount];
        // return f(amount, coins, coins.size()-1,dp);
    }
};