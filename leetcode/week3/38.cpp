class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=0;i<n-1;i++){
            string t;
            for(int j=0;j<s.size();){//注意这里别写错了
                int k=j+1;
                while(k<s.size()&&s[j]==s[k]) k++;
                t+=(to_string(k-j)+s[j]);
                j=k;
            }
            s=t;
        }
        return s;
    }
};
