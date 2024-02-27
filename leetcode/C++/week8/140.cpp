class Solution {
public:
    vector<string> ans;
    unordered_set<string> set;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) {
            set.insert(word);
        }

        dfs(s, 0, "");
        return ans;
    }

    void dfs(string s, int start, string path) {
        if (start == s.length()) {
            ans.push_back(path);
        }
        /**
        * i<10:利用给的数据范围进行剪枝
        * 若想进一步剪枝，可先利用动态规划算出f数组(与139题过程相同)，
        * 利用该数组可知在哪些地方对s进行拆分是合适的
        */
        for (int i = 0; i < 10 && start + i < s.length(); i++) {
            string tmpPath = path;
            if (set.count(s.substr(start, i + 1))) {
                if (start + i == s.length() - 1) {
                    tmpPath = tmpPath + s.substr(start, i + 1);
                }
                else {
                    tmpPath = tmpPath + s.substr(start, i + 1) + " ";
                }
                dfs(s, start + i + 1, tmpPath);
            }
        }
    }
};