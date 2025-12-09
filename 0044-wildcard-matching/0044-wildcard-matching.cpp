class Solution {
public:
    bool f(string &s, string &p, int i, int j, vector<vector<int>>& dp) {

        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;

        if (i < 0 && j >= 0) {
            for (int jj = j; jj >= 0; jj--) {
                if (p[jj] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = f(s, p, i - 1, j - 1, dp);

        if (p[j] == '*')
            return dp[i][j] = f(s, p, i - 1, j, dp)     // '*' consumes s[i]
                            || f(s, p, i, j - 1, dp);   // '*' consumes empty

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(s, p, n - 1, m - 1, dp);
    }
};
