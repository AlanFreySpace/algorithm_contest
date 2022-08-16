class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        s=' '+s;
        vector<int> f(n+1);
        f[0]=1;//注意此处的初始条件很巧妙

        for(int i=1;i<=n;i++){
            if(s[i]!='0') f[i]+=f[i-1];
            if(i>1){
                int tmp=(s[i-1]-'0')*10+s[i]-'0';
                if(tmp>=10&&tmp<=26) f[i]+=f[i-2];
            }
        }
        return f[n];
    }
};
