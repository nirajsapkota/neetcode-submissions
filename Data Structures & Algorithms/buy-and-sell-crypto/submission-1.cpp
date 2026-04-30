class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        auto max_profit = 0;
        auto buy_price = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            // If we were to sell at this price
            max_profit = std::max(max_profit, prices[i] - buy_price);
            // Change this to be the buy price, if better than our current buy price
            buy_price = std::min(buy_price, prices[i]);
        }
        return max_profit;
    }
};
