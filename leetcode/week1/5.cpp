class Solution {
public:
    string longestPalindrome(string s) {//利用指针枚举中心 复杂度O(n^2)
        string res;
        for(int i=0;i<s.size();i++){//枚举中心点
            int l=i-1,r=i+1;//长度为奇数的回文串
            while(l>=0&&r<s.size()&&s[l]==s[r]) l--,r++;
            if(res.size()<r-l-1) res=s.substr(l+1,r-l-1);//注意substr的调用方法

            l=i,r=i+1;//长度为偶数的回文串
            while(l>=0&&r<s.size()&&s[l]==s[r]) l--,r++;
            if(res.size()<r-l-1) res=s.substr(l+1,r-l-1);
        }
        return res;
    }
};
