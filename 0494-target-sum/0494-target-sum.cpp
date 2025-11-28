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
        
        return helper(nums, target, 0,0,0);

    }
};