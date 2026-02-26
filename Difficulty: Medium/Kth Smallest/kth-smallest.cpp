class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        if(k>0)
        return arr[k-1];
    
        return arr[k];
    }
};