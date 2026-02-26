class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n =arr.size();
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i =0 ; i< n ; i++){
             sum = max(arr[i], sum+arr[i]);
             max_sum = max(sum, max_sum);
        }
        
        
        return max_sum;
        
    }
};