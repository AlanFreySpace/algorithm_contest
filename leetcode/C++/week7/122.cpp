class Solution {
public:
    // 贪心法：策略即若股票价格不断升高就不卖 股票价格一降低就立刻卖出
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                res += (prices[i] - prices[i - 1]);
            }
        }
        return res;
    }
};