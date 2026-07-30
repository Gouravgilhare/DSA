class Solution {
public:
    // int helper(int i , int j , string &a, string&b ,vector<vector<int>>&dp){
    //     if(i==0) return j;
    //     if(j==0) return i;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(a[i-1]==b[j-1]) return dp[i][j] =  helper(i-1, j-1, a, b, dp);
    //     return dp[i][j] = 1 + min( 
    //         helper(i-1, j, a, b, dp),
    //        min( helper(i, j-1, a, b, dp),
    //        helper(i-1, j-1, a, b, dp) ));
    // }
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n==0) return m;
        // vector<vector<int>>dp(n+1 ,vector<int>(m+1,-1));
        vector<int>curr(m+1,0), prev(m+1,0);
        for(int j = 0 ; j<=m ; j++){
            prev[j]= j;
        } 

        for(int i = 1 ; i<= n ; i++){
            curr[0]=i;
            for(int j = 1; j<=m ; j++){

                if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min(prev[j], min(curr[j-1], prev[j-1]));
            }
            prev=curr;
        }

        return prev[m];

    }
};