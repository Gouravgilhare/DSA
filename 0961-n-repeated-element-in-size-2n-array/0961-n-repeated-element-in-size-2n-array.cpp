class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(auto a : nums){
            mp[a]++;
        }
        int maxEle = INT_MIN;
        int curr = 0;

        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(it->second > maxEle){
                maxEle = it->second;
                curr=it->first;
            }
        }

        return curr;

    }
};