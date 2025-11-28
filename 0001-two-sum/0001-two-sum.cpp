class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int>mp;
        for(int i = 0 ; i< n ;i++){
            mp[nums[i]]=i ;
        }
        vector<int>ans;
        for(int i = 0 ; i< n ; i++){
            int newTarget = target -nums[i];
            if(mp.find(newTarget)!= mp.end()&& mp[newTarget]!= i) {
                ans.push_back(mp[newTarget]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};