class Solution {
public:
    int f(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        int n = s.size(); 
        int m = t.size(); 
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1 ) return dp[i][j];
        if(s[i] == t[j]) {
            return f(s,t,i-1, j -1, dp);
        }    

        return dp[i][j] = 1 + min (f(s,t,i-1, j -1,dp), min ( f(s,t, i-1,j,dp), f(s,t,i,j-1,dp)));
    }

    int minDistance(string s, string t) {
        int n = s.size(); 
        int m = t.size(); 
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = 0 ; i<=n ; i++){
            dp[i][0] = i;
        }
        for(int i = 0 ; i<=m ; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=m ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }



        return dp[n][m];

        // return f(word1, word2, n -1, m-1, dp);

    }
};