class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        vector<int> f(n + 1);

        /**
        * isPalin[i][j]:表示s[i..j]是否是回文串
        */
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    isPalin[i][j] = true;
                }
                else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || isPalin[i + 1][j - 1]) {
                        isPalin[i][j] = true;
                    }
                }
            }
        }

        /**
        * f[j+1]:表示把s[0..j]划分成回文串，最少可划分成几部分
        * 动归步骤：
        * 依次考察以s[j]结尾的子串s[0..j]，对每个子串s[0..j]，
        * 尝试将s[i..j]作为最后一个回文串
        */
        f[0] = 0;
        for (int j = 0; j < n; j++) {
            f[j + 1] = INT_MAX;
            for (int i = 0; i <= j; i++) {
                if (isPalin[i][j]) {
                    f[j + 1] = min(f[j + 1], f[i] + 1);
                }
            }
        }

        return f[n] - 1;
    }
};