class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> f(n + 1, 0);

        // ��ʼ��:����Ϊi���ַ��������ָ�i-1��
        for (int i = 0; i <= n; i++) {
            f[i] = i - 1;
        }

        for (int i = 1; i <= n; i++) {
            // ����Ϊ�����Ļ��Ĵ�
            for (int j = 0; i - j >= 1 && i + j <= n && s[i - j - 1] == s[i + j - 1]; j++) {
                f[i + j] = min(f[i + j], f[i - j - 1] + 1);
            }

            // ����Ϊż���Ļ��Ĵ�
            for (int j = 1; i - j >= 0 && i + j <= n && s[i - j] == s[i + j - 1]; j++) {
                f[i + j] = min(f[i + j], f[i - j] + 1);
            }
        }

        return f[n];
    }
};