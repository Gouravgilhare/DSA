class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> best(k, LLONG_MAX); // min prefix sum for each mod
        long long prefix = 0;
        long long ans = LLONG_MIN;

        best[0] = 0; // prefix before start

        for(int i = 0; i < n; i++) {
            prefix += nums[i];

            int mod = (i + 1) % k;

            // If a previous prefix with same mod exists → valid subarray
            if(best[mod] != LLONG_MAX)
                ans = max(ans, prefix - best[mod]);

            // Store minimum prefix sum for this mod
            best[mod] = min(best[mod], prefix);
        }

        return ans;
    }
};

