class Solution {
  public:

    int rec(vector<int>&arr, int buy , int i, int  k, vector<vector<vector<int>>>&dp){
        int n = arr.size();
        if(i == n  || k ==0)return 0;
        if(dp[i][buy][k]!= -1) return dp[i][buy][k];
        int profit = 0;
        if(buy){
            profit = max(-arr[i] + rec(arr,0 ,i+1, k, dp),  0 + rec(arr, 1, i+1, k, dp) );
        }else {
            profit = max(arr[i] +  rec(arr,1 ,i+1, k-1, dp),  0 + rec(arr, 0, i+1, k, dp) );
        }
        
        
        return  dp[i][buy][k]=profit;
    }
  
  
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1 ,vector<vector<int>>(2, vector<int>(k+1,-1)) );
        
        return rec(prices,1, 0, k, dp);
    }
};