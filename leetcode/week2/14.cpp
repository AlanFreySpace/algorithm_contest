class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//ע��ǰ׺��������
        string res;
        if(strs.empty()) return res;

        for(int i=0;i<strs[0].size();i++){
            int c=strs[0][i];
            for(auto& str:strs){//ע��˴������ñ����Ǹ����
                if(i==str.size()||str[i]!=c) return res;//�±�Խ����ַ���ͬ
            }
            res+=c;
        }
        return res;
    }
};
