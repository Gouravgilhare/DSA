class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n= wt.size();
        vector<int>prev(W+1, 0);
        for(int i = wt[0] ; i<=W ; i++){
            prev[i]= val[0];
        }
        
        for(int i = 1; i<n ;i++  ){
            for(int j = W; j>=0 ; j--){
                int notTake = prev[j];
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + prev[j - wt[i]];
                
                prev[j] = max(notTake , take);
                
            }
        }
        
        
        return prev[W];
    }
};