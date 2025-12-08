class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        int n = val.size();
        vector<long long>prev(W+1, 0),curr(W+1, 0);
        for(int i = 0 ; i<= W; i++){
            prev[i] = (i/wt[0]) * val[0];
        }
        
        for(int i = 1; i<n ; i++){
            for(int j = 0 ; j<= W; j++){
                
                long long notTake = prev[j];
                long long take = 0;
                if(wt[i]<= j){
                    take = val[i]+ curr[j-wt[i]];
                }
                curr[j] = max(take,notTake);
            }
            
            prev = curr;
        }
        
        
        
        return prev[W];
    }
};