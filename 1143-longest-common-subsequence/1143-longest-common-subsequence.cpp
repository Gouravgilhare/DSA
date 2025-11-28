class Solution {
public:

int dp[1001][1001];

    int helper(string &text1, string &text2, int i, int j ) {
        int n = text1.size(), m = text2.size();
        if( i == n || j == m) return 0;

        if(dp[i][j]!=-1){
                return dp[i][j];
        }


        if(text1[i]==text2[j]){
            return dp[i][j] = 1+helper(text1, text2, i+1, j+1);
        }
         
        

        return  dp[i][j] =max(
            helper(text1,text2, i+1, j),
            helper(text1,text2, i, j+1)
        );
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return helper(text1, text2, 0,0);
    }
};