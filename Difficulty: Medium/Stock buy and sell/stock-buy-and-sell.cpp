class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int bestBuy = arr[0] ; 
        int profit = 0;
        
        for(int i = 1; i< n ;i++){
           
            
            if(arr[i]>arr[i-1])
                profit += arr[i] - arr[i-1];
            
            // bestBuy = min(bestBuy, arr[i]);
        }
        
        
        return profit;
    }
};