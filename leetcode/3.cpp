class Solution {
public:
    int lengthOfLongestSubstring(string s) {//双指针 滑动窗口算法 O(n)时间复杂度
        unordered_map<char,int> m;
        int res=0;
        /*
        计算以s[i]结尾的不含重复字符子串的最大长度
        */
        for(int i=0,j=0;i<s.size();i++){//i是右指针 j是左指针
            m[s[i]]++;
            while(m[s[i]]>1) m[s[j++]]--;//左指针右移以消除重复字符
            res=max(res,i-j+1);
        }
        return res;
    }
};
