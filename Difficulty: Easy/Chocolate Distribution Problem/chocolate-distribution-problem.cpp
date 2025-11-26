class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int res = INT_MAX ;
        //slidding window
        
        sort(a.begin(), a.end());
        int n = a.size();
        for(int i = 0 ; i<=n-m; i++){
            int minEle = a[i];
            int maxEle = a[i+m-1];
            
            res= min(res, maxEle-minEle);
        }
        
        
        return res;
    }
};