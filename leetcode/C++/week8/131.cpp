class Solution {
public:
    vector<vector<bool>> f;
    vector<vector<string>> ans;
    vector<string> path;
    int n;

    /** 
    * f[i][j]:表示s[i..j]是否是回文串
    */
    vector<vector<string>> partition(string s) {
        n = s.length();
        f = vector(n, vector<bool>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    f[i][j] = true;
                }
                else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || f[i + 1][j - 1]) {
                        f[i][j] = true;
                    }
                }
            }
        }

        dfs(0, s);
        return ans;
    }
    
    // from:递归搜索当前处理到的位置
    void dfs(int from, string& s) {
        if (from == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = from; i < s.size(); i++) {
            if (f[from][i]) {
                path.push_back(s.substr(from, i - from + 1));
                dfs(i + 1, s);
                path.pop_back();
            }
        }
    }
};