class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        vector<int> dp(m, 1);

        for (int i = m - 2; i >= 0; i--) {
            for (int j = i + 1; j < m; j++) {

                bool ok = true;
                for (string &row : strs) {
                    if (row[i] > row[j]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int kept = 0;
        for (int x : dp) kept = max(kept, x);
        return m - kept;
    }
};
