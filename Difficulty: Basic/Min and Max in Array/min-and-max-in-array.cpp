class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int max_ele = *max_element(arr.begin(), arr.end());
        int min_ele = *min_element(arr.begin(), arr.end());
        
        vector<int>ans;
        ans.push_back(min_ele);
        ans.push_back(max_ele);
        
        return ans;
        
    }
};