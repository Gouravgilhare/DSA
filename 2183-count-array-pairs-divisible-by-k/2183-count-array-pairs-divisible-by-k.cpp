class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int>mp;
        for(int i = 0 ; i< nums.size(); i++){
            int get = gcd(nums[i],k);
            int need = k/get;

            for(auto it : mp){
                if(it.first%need == 0)
                    ans += it.second;
            }
            mp[get]++;
        }


        return ans;
    }
};