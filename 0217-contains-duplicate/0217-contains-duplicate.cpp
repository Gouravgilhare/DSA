class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;

        for(auto a: nums){
            if(st.count(a)){
                return true;
            }
            st.insert(a);
        }       

        return false;
    }
};