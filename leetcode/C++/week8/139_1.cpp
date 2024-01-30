class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        s = " " + s;
        unordered_set<string> set;
        vector<bool> f(s.length(), false);

        for (int i = 0; i < wordDict.size(); i++) {
            set.insert(wordDict[i]);
        }

        f[0] = true;

        for (int i = 1; i < s.length(); i++) {
            for (int j = 1; j <= 20 && j <= i; j++) {
                if (f[i - j] && set.count(s.substr(i - j + 1, j))) {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[s.length() - 1];
    }
};