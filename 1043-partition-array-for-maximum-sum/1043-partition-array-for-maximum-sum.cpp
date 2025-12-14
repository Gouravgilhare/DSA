class Solution {
public:
    int f(int ind, vector<int>&arr, int k ,vector<int>&dp){
        int n = arr.size();
        if(ind == n) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns= INT_MIN;
        for(int j = ind; j<min(n, ind+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len*maxi + f(j+1, arr, k ,dp);
            maxAns = max(maxAns, sum);
        }


        return dp[ind] = maxAns;


    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, 0);

        for(int i = n-1; i>=0; i--){
                int len = 0;
            int maxi = INT_MIN;
            int maxAns= INT_MIN;
            for(int j = i; j<min(n, i+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len*maxi + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }

        return dp[0];
    }
};