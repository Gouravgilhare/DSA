// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        int n  = arr.size();
        int sum = 0;
        sort(arr.begin(), arr.end());
        
        int left = 0, right = n -1;
        
        vector<vector<int>>ans;
        
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == 0) {
                ans.push_back({arr[left], arr[right]});
                
                int lval = arr[left];
                int rval = arr[right];
            
                while(arr[left]==lval) left++;
                while(arr[right]==rval) right--;
            }
            else if(sum < 0)left++;
            else right--;
        }
        
        
        
        return  ans;
        
    }
};