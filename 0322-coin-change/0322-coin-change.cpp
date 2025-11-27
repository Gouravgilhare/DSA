class Solution {
public:
    int coinChange(vector<int>& c, int a) {
        if(a < 0) return -1;


        vector<int>dp(a+1, INT_MAX) ;

            dp[0]=0;
            for(int i = 1; i<=a; i++){
                dp[i] = INT_MAX;
                for(auto coin  : c){
                    if(coin <= i && dp[i - coin] != INT_MAX)
                    {
                        dp[i] = min(dp[i-coin]+1,dp[i] );
                    }
                }

            }

        if(dp[a]==INT_MAX)return -1;
        return dp[a];
    }
};