class Solution {
public:
    vector<vector<bool>> f;
    vector<vector<string>> ans;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        int n = s.length();
        f = vector(n, vector<bool>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    f[i][j] = true;
                    cout << i << " " << j << endl;
                }
                else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || f[i + 1][j - 1]) {
                        f[i][j] = true;
                        cout << i << " " << j << endl;
                    }
                }
            }
        }

        return ans;
    }
};