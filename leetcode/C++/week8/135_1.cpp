class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> f(n, 1);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                f[i] = f[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                f[i] = max(f[i], f[i + 1] + 1);
            }
            ans += f[i];
        }
        ans += f[n - 1];

        return ans;
    }
};