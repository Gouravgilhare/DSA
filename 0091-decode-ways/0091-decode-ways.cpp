class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for(int i = 2; i<=n ; i++){
            int d1 = s[i-1]-'0';
            int d2 = (s[i-2]-'0')*10 + (s[i-1]-'0');

            if(d1 >=1 )
                dp[i] = dp[i-1];
            
            if(d2 >= 10 && d2 <=26)
                dp[i] += dp[i-2];

        }

        return dp[n];
    }
};