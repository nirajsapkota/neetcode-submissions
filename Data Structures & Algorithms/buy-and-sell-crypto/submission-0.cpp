class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            auto buy_price = prices[i];
            for (int j = i + 1; j < prices.size(); j++) {
                auto sell_price = prices[j];
                auto profit = sell_price - buy_price;
                max_profit = std::max(max_profit, profit);
            }
        }
        return max_profit;
    }
};
