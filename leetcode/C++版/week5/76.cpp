class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hs,ht;
        for(auto c:t) ht[c]++;

        string res;
        int cnt=0;//有效字符数
        for(int i=0,j=0;i<s.size();i++){
            hs[s[i]]++;//s[i]是结尾字符
            if(hs[s[i]]<=ht[s[i]]) cnt++;//更新有效字符数

            while(j<s.size()&&hs[s[j]]>ht[s[j]]) hs[s[j++]]--;//更新首字符
            if(cnt==t.size()){
                if(res.empty()||res.size()>i-j+1)
                    res=s.substr(j,i-j+1);
            }
        }

        return res;
    }
};
