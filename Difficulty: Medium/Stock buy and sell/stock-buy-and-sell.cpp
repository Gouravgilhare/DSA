class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int buy= arr[0];
        int sell = arr[0];
        int profit = 0;
        
        for(int i = 0 ; i< n-1 ; i++){
            if(arr[i+1] < arr[i])
            {
                sell = arr[i];
            
            profit += sell - buy ;
            buy = arr[i+1];
            }            
        }
        
        profit+=(arr[n-1] - buy);
        
        
        return profit;
        
    }
};