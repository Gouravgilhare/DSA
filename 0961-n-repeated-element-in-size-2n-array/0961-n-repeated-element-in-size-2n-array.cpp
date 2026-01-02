class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i= 0 ; i< n-2 ; i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2])
                return nums[i];
        }

        return nums[n-1];

    }
};