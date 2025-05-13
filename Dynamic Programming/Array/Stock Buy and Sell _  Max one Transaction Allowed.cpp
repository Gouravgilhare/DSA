class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int minprice = INT_MAX ; 

        for( auto a : prices){
            minprice = min( minprice, a);
            max_profit= max( max_profit, a -minprice);
        }

        return max_profit;
    }
};
