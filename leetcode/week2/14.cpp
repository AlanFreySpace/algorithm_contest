class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//注意前缀是连续的
        string res;
        if(strs.empty()) return res;

        for(int i=0;i<strs[0].size();i++){
            int c=strs[0][i];
            for(auto& str:strs){//注意此处传引用遍历是更快的
                if(i==str.size()||str[i]!=c) return res;//下标越界或字符不同
            }
            res+=c;
        }
        return res;
    }
};
