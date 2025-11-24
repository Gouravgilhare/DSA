class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        vector<bool>ans;
        vector<int>bin;
        for(int i = 0 ; i< n; i++){
            curr = (curr * 2 + nums[i])%5;
            if(curr %5 ==0 ) ans.push_back(true);
            else ans.push_back(false);
        }


        return ans;

    }
};