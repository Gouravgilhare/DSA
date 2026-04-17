class Solution {
  public:
    int maxScore(vector<int>& arr, int k) {
        // code here.
        int n = arr.size();
        
        int l = 0,  r = n -1;
        int lsum = 0 ; 
        // int maxSum = 0;
        for(int i = 0 ; i < k ; i++){
            lsum += arr[i];
        }
      
        int maxsum = lsum ;
        int rsum = 0;
        for(int i = k -1; i>=0 ; i--){
            lsum -= arr[i];
            rsum += arr[r];
            maxsum = max(maxsum, lsum+rsum);
            r--;
        }
        
        return maxsum ;
    }
};
