class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);

        // Compute left[i] - length of increasing subarray ending at i
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                left[i] = left[i - 1] + 1;
        }

        // Compute right[i] - length of increasing subarray starting at i
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            // Adjacent subarrays boundary between i and i+1
            ans = max(ans, min(left[i], right[i + 1]));
        }

        return ans;
    }
};
