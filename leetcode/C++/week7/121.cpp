class Solution {
public:
    /*
    res:每次循环时,试着以prices[i]为卖出价进行卖出，对应的买入价为该循环之前的
    股票最低价格。最尝试卖出的利润prices[i] - minPrice > res,则更新res为该利润。
    否则维持最高利润res不变。
    minPrice:当前循环及之前循环结束后,股票的最低买入价
    */
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res = max(prices[i] - minPrice, res);
            minPrice = min(minPrice, prices[i]);
        }
        return res;
    }
};