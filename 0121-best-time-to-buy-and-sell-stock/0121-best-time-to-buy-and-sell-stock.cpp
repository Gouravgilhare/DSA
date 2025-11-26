class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int max_profit = 0;

        for(int i = 1; i < prices.size(); i++){
            int curr_profit = prices[i] - buy;
            if(curr_profit > max_profit){
                max_profit = curr_profit;
            }
            if(prices[i] < buy ){
                buy = prices[i];
            }
        }

        return max_profit;
    }
};