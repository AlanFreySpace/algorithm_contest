class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> f;
        f.push_back(0);
        int minPrice = prices[0], temp = 0, n = prices.size(), maxPrice = prices[n - 1];
        if (n == 1) {
            return 0;
        }
        for (int i = 1; i < n; i++) {
            temp = max(temp, prices[i] - minPrice);
            f.push_back(temp);
            minPrice = min(minPrice, prices[i]);
        }
        temp = 0;
        int res = max(f[n - 1], f[n - 2]);
        for (int i = n - 2; i > 0; i--) {
            temp = max(temp, maxPrice - prices[i]);
            f[i - 1] += temp;
            res = max(res, f[i - 1]);
            maxPrice = max(maxPrice, prices[i]);
        }
        return res;
    }
};