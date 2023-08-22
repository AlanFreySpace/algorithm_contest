class Solution {
public:
    bool check(char c) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            // 注意i<j的边界条件时刻不能丢 i应该在j的左边
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