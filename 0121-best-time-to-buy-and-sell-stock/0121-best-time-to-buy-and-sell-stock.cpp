class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy= 0;
        for(int i =0 ; i< n ; i++){
           if(prices[buy] < prices[i]){
            maxProfit = max(maxProfit, prices[i]-prices[buy]);
           }else{
            buy=i;
           }
        }
        return maxProfit;
    }
};