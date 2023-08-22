class Solution {
public:
    bool check(char c) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            // ע��i<j�ı߽�����ʱ�̲��ܶ� iӦ����j�����
            while (i < j && !check(s[i])) {
                i++;
            }
            while (i < j && !check(s[j])) {
                j--;
            }
            if (s[i] != s[j] && s[i] != (s[j] ^ 32)) {
                return false;
            }
            i++, j--;
        }

        return true;
    }
};