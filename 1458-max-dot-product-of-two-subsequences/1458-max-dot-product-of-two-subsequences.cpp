#pragma GCC optimize("O3, unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        // Ensure nums1 is the larger array
        if (n1 < n2)
            return maxDotProduct(nums2, nums1);

        vector<vector<int>> dp(2, vector<int>(n2 + 1, INT_MIN));
        int result = INT_MIN;

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int prod = nums1[i] * nums2[j];

                int take_only = prod;
                int take_extend = prod + max(0, dp[(i + 1) & 1][j + 1]);
                int skip1 = dp[(i + 1) & 1][j];
                int skip2 = dp[i & 1][j + 1];

                dp[i & 1][j] = max({take_only, take_extend, skip1, skip2});
                result = max(result, dp[i & 1][j]);
            }
        }
        return result;
    }
};
