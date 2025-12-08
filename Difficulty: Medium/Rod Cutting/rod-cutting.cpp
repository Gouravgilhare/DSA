// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int>prev(n+1, 0);
        for(int i = 0 ; i<= n ; i++){
            prev[i] = i*price[0];
        }
        
        for(int i = 1; i< n ; i++){
                int rodlength = i+1;
            for(int j = 0; j<= n ; j++){
                int notTake = prev[j];
                int take = INT_MIN;
                
                if(rodlength <=j){
                    take = price[i] + prev[j-rodlength];
                }
                
                prev[j] = max(take, notTake);
                
            }
        }
        
        
        return prev[n];
    }
};