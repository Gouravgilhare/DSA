class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        sort(a.begin(), a.end());
        int minEle = INT_MAX;
        for(int i = 0 ;i< n -m +1; i++){
            if( a[i+m-1] -a[i] < minEle){
                minEle = a[i+m-1] - a[i];
            }
        }
        
        return minEle;
    }
};