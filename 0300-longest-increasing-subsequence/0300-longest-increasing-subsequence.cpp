class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();


        vector<int>dp(n, 1);
        int maxAns = 1;
        int cnt = 0;
        for(int i = 0 ; i<n ;i++){
            for(int j =0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                    
                    maxAns = max(maxAns, dp[i]);
                }
            }
        }


        return maxAns;
    }
};