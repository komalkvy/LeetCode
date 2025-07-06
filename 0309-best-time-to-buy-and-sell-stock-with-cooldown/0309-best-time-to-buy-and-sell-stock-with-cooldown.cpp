class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_buy = 0, prev_sell = 0, buy = INT_MIN, sell = 0;
        for(int i = 0, days = prices.size(); i < days; ++i){
            prev_buy = buy;
            buy = max(buy , prev_sell - prices[i]);
            prev_sell = sell;
            sell = max(sell , prev_buy + prices[i]);
        }
        return sell;
    }
};