class Solution {
public:

    int maxSum(vector<int>&nums, int i, int sum){
        int n = nums.size();
        if(i ==n ) return sum ;

        sum+= nums[i];
        int temp = maxSum(nums, i+1, sum);

        if(temp%3 == 0 )return sum; 

        sum -= nums[i];

        return maxSum(nums, i+1, sum);

    }

    int maxSumDivThree(vector<int>& nums) {
     int n = nums.size();
        vector<int>dp(3,0);

        for(int num : nums){
            vector<int>temp = dp;

            for(int i = 0 ; i< 3; i++){
                int newMod = (temp[i]+num)%3;
                dp[newMod] = max(dp[newMod], temp[i]+num);
            }

        }
        return dp[0];
        // return maxSum(nums, 0, 0);
    }
};