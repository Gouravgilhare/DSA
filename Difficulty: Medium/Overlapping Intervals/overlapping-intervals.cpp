class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        
        
        sort (arr.begin(), arr.end());
        
        vector<vector<int>>ans;
            int left = arr[0][0];      
            int right = arr[0][1];      
        for(int i = 1; i< n ; i++){
           
           
          if(right >= arr[i][0]){
               right = max(right, arr[i][1]);
          }
           
          else{
               ans.push_back({left, right});
               left = arr[i][0];
               right =arr[i][1];
          }
           
           
           
        }
            ans.push_back({left,right});
        
        
        
        return ans;
    }
};