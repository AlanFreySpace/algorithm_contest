class Solution {
public:
    string longestPalindrome(string s) {//����ָ��ö������ ���Ӷ�O(n^2)
        string res;
        for(int i=0;i<s.size();i++){//ö�����ĵ�
            int l=i-1,r=i+1;//����Ϊ�����Ļ��Ĵ�
            while(l>=0&&r<s.size()&&s[l]==s[r]) l--,r++;
            if(res.size()<r-l-1) res=s.substr(l+1,r-l-1);//ע��substr�ĵ��÷���

            l=i,r=i+1;//����Ϊż���Ļ��Ĵ�
            while(l>=0&&r<s.size()&&s[l]==s[r]) l--,r++;
            if(res.size()<r-l-1) res=s.substr(l+1,r-l-1);
        }
        return res;
    }
};
