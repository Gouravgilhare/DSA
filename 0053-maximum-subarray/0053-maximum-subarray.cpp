class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int curSum = 0;

        //kadanes algorithm
        for(auto a: nums){
            curSum += a;
            maxSum = max(maxSum , curSum);
            if(curSum <= 0) curSum = 0;
        }
        return maxSum;
    }
};