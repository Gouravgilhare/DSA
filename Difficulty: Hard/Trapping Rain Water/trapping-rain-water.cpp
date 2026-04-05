class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int>left(n),right(n);
        int leftMax = arr[0];
        int rightMax = arr[n-1];
        for(int i = 0; i< n; i++){
            leftMax = max(leftMax, arr[i]);
            left[i] = leftMax;
        }
        for(int i = n-1; i >=0 ; i--){
            rightMax = max(rightMax, arr[i]);
            right[i] = rightMax;
        }
        
        int totalWater = 0 ;
        
        for(int i = 0 ;i< n ; i++){
            
            totalWater += min(left[i],right[i] ) - arr[i];
        }
        
        
        return totalWater;
        
    }
};