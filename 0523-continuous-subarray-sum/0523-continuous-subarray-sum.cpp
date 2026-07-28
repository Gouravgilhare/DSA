class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 1; i< n ; i++){
            nums[i] += nums[i-1];
        }

        for(int i = 0 ; i< n ; i++){
            nums[i] %= k;
        }

        unordered_map<int,int>mp;
        mp[0]= -1;

        for(int i = 0 ; i< n ; i++){
           int rem = nums[i] % k;

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;   // don't overwrite first occurrence
            }
        }

        return false;
    }
};