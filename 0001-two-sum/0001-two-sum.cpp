class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>arr;
        unordered_map<int,int>mp;
        int temp ;
        for(int i =0 ; i< n ; i++){
            temp = target - nums[i];
            if(mp.find(temp)!= mp.end()){
                arr.push_back(mp[temp]);
                arr.push_back(i);
            }
            else{
                mp[nums[i]] = i;
            }
            
        }
        return arr;
    }
};