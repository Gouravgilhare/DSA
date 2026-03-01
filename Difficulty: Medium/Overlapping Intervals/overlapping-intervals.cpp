class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        int m = arr[0].size();
        
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        int first= arr[0][0];
        int last= arr[0][1];
        
       for(int i = 1 ; i <n  ; i++){
           if(last >= arr[i][0] )
           {
               if(arr[i][1]  >  last)
                last =arr[i][1];
           }
           else if( last < arr[i][0]){
               ans.push_back({first, last});
                first  = arr[i][0];
                last = arr[i][1];
           }
               
       }
       
       ans.push_back({first,last});
       
       return ans;
            
        
    }
};