class Solution {
public:

    int helper(vector<int>&nums, int target , int sum, int cnt, int index){
        
        if(index == nums.size()){ 
               
            return sum == target? 1: 0;
        }
        
        int take  = helper(nums, target, sum+nums[index],cnt, index+1);
        int notTake = helper(nums, target, sum-nums[index],cnt, index+1);

        return take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        // return helper(nums, target, 0,0,0);
        int n = nums.size();
        int totalSum =0 ;
        for(int i : nums){
            totalSum += i;
        }

        if((totalSum+target)%2!=0 || (totalSum < abs(target)))return 0;

        int P = (totalSum+target)/2;
        vector<int>dp(P+1, 0);
        dp[0]=1;
        for(auto num : nums){

            for(int i = P; i>=num; i-- ){
                dp[i] += dp[i-num];
            }

        }

        return dp[P];

    }
};