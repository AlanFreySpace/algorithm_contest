class Solution {
public:
    bool isMatch(string s, string p) {//���ö�̬�滮������� ʱ�临�Ӷ�O(n*m)
        int n=s.size(),m=p.size();
        s=' '+s,p=' '+p;
        vector<vector<bool>> f(n+1,vector<bool>(m+1));

        f[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j]=='*')
                    f[i][j]=f[i][j-1]||(i&&f[i-1][j]);
                else
                    f[i][j]=(s[i]==p[j]||p[j]=='?')&&(i&&f[i-1][j-1]);
            }
        }
        return f[n][m];
    }
};
