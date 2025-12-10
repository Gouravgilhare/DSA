class Solution {
public:
    int f(int ind, int buy,int cap, vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(ind == n) return 0;
        if(cap == 0) return 0;
        if(dp[ind][buy][cap]!= -1) return dp[ind][buy][cap];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind]+f(ind+1, 0, cap, prices ,dp), 0+f(ind+1, 1, cap, prices,dp));
        }else
            profit = max(prices[ind]+f(ind+1, 1, cap-1, prices,dp), 0+f(ind+1, 0, cap, prices,dp));

        return  dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>>prev(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        prev[0][0]= prev[1][0]=0;
        for(int ind =n-1; ind>= 0; ind--){
            for(int buy = 0 ; buy<2; buy++){
                for(int cap = 1 ; cap <=2 ; cap++){

                    long profit = 0;

                    if(buy) {
                        profit = max(-prices[ind]+ prev[0][cap], prev[1][cap]);
                    }else{
                        profit = max(prices[ind]+ prev[1][cap-1], prev[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            prev = curr; 
        }


        return prev[1][2];
        // return f(0,1,2,prices,dp);
    }
};