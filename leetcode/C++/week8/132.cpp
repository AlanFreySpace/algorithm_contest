class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        vector<int> f(n + 1);

        /**
        * isPalin[i][j]:��ʾs[i..j]�Ƿ��ǻ��Ĵ�
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
        * f[j+1]:��ʾ��s[0..j]���ֳɻ��Ĵ������ٿɻ��ֳɼ�����
        * ���鲽�裺
        * ���ο�����s[j]��β���Ӵ�s[0..j]����ÿ���Ӵ�s[0..j]��
        * ���Խ�s[i..j]��Ϊ���һ�����Ĵ�
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