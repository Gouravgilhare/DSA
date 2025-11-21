class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int>st;
        int n = arr.size();
        vector<int>ans(n);
            
        // ans.push_back(-1);
       for(int i = 0; i< n ; i++){
           while(!st.empty() && st.top() >= arr[i])
            st.pop();
            
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            
            st.push(arr[i]);
            
       }
        return ans;
    }
};