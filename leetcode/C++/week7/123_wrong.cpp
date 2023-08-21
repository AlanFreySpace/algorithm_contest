class Solution {
public:
    /*
    123题的错误贪心解法,关于该算法具体的错误之处参见本周的doc文档笔记
    */
    int maxProfit(vector<int>& prices) {
        int firstMax = 0, secondMax = 0;
        for (int i = 0, j = 1; j < prices.size();) {
            while (j < prices.size() && prices[j] > prices[j - 1]) {
                j++;
            }
            int nowMax = prices[j - 1] - prices[i];
            if (nowMax > firstMax) {
                secondMax = firstMax;
                firstMax = nowMax;
            }
            else if (nowMax > secondMax) {
                secondMax = nowMax;
            }
            i = j;
            j++;
        }

        return firstMax + secondMax;
    }
};