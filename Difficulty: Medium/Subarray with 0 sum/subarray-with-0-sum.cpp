class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        
        unordered_set<int>st;
        int preSum= 0;
        
        for(int i = 0 ; i< n ; i++){
            preSum += arr[i];
            
            if(preSum == 0 || st.count(preSum)){
                return true;
            }
            
            st.insert(preSum);
        }
        
        
        return false;
    }
};