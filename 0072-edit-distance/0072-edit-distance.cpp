class Solution {
public:
    int helper(int i , int j , string &a, string&b ,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i]==b[j]) return dp[i][j] =  helper(i-1, j-1, a, b, dp);
        return dp[i][j] = 1 + min( 
            helper(i-1, j, a, b, dp),
           min( helper(i, j-1, a, b, dp),
           helper(i-1, j-1, a, b, dp) ));
    }
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n ,vector<int>(m,-1));
        return helper(n-1, m-1,s1, s2, dp);

    }
};