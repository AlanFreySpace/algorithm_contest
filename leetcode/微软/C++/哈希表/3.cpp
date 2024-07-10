class Solution {
public:
    int lengthOfLongestSubstring(string s) { //双指针 滑动窗口算法 O(n)时间复杂度
        unordered_map<char, int> hash;
        int res = 0;
        //计算以s[j]结尾的不含重复字符子串的最大长度
        for (int i = 0, j = 0; j < s.length(); j++) { //i是左指针 j是右指针
            hash[s[j]]++;
            while (hash[s[j]] > 1) {
                hash[s[i++]]--; //左指针右移以消除重复字符
            }
            res = max(res, j - i + 1);
        }

        return res;
    }
};