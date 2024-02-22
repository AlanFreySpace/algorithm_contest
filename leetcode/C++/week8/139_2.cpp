class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        typedef unsigned long long ULL;
        unordered_set<ULL> set;
        const int P = 131;

        for (string word : wordDict) {
            ULL h = 0;
            for (int i = word.length() - 1; i >= 0; i--) {
                h = h * P + word[i];
            }
            set.insert(h);
        }

        s = " " + s;
        int n = s.length();
        vector<bool> f(n, false);
        f[0] = true;
        for (int i = 1; i < n; i++) {
            ULL h = 0;
            for (int j = 1; j <= i && j <= 20; j++) {
                h = h * P + s[i - j + 1];
                if (f[i - j] && set.count(h)) {
                    f[i] = true;
                }
            }
        }

        return f[n - 1];
    }
};