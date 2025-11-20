class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        stack<int>st;
        vector<int>nge;
        unordered_map<int, int>mp;

        for(int i = n2-1; i>=0 ;i--){
            
            while(!st.empty() && nums2[i] >=st.top()){
                    st.pop();
            }
            mp[nums2[i]]=st.empty()?-1 : st.top();

            st.push(nums2[i]);
       }

        for(auto a : nums1){
            nge.push_back(mp[a]);
        }

        return nge;
    }
};