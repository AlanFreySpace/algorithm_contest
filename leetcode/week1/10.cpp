class Solution {//利用动态规划求解 时间复杂度O(n^2)
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        s=' '+s,p=' '+p;
        vector<vector<bool>> f(n+1,vector<bool>(m+1));
        f[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j+1<=m&&p[j+1]=='*') continue;//应归入*匹配的情况
                if(i&&p[j]!='*')//注意运算符优先级 用(s[i]==p[j]||p[j]=='.')表示
                    f[i][j]=(s[i]==p[j]||p[j]=='.')&&f[i-1][j-1];
                if(p[j]=='*')
                    f[i][j]=f[i][j-2]||(i&&f[i-1][j])&&(s[i]==p[j-1]||p[j-1]=='.');
            }
        }
        return f[n][m];
    }
};
