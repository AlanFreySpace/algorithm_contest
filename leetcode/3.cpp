class Solution {
public:
    int lengthOfLongestSubstring(string s) {//˫ָ�� ���������㷨 O(n)ʱ�临�Ӷ�
        unordered_map<char,int> m;
        int res=0;
        /*
        ������s[i]��β�Ĳ����ظ��ַ��Ӵ�����󳤶�
        */
        for(int i=0,j=0;i<s.size();i++){//i����ָ�� j����ָ��
            m[s[i]]++;
            while(m[s[i]]>1) m[s[j++]]--;//��ָ�������������ظ��ַ�
            res=max(res,i-j+1);
        }
        return res;
    }
};
