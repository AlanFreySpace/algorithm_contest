class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size();
        if(n+m!=s3.size()) return false;

        /*
        f[i][j]代表由长度为i的s1的前缀和长度为j的s2的前缀能否组成
        长度为i+j的s3的前缀.其中s1,s2,s3均指未加空格前的串。
        */
        s1=' '+s1,s2=' '+s2,s3=' '+s3;
        vector<vector<bool>> f(n+1,vector<bool>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(!i&&!j) f[i][j]=true;
                else{
                    if(i&&s3[i+j]==s1[i]) f[i][j]=f[i-1][j];
                    if(j&&s3[i+j]==s2[j]) f[i][j]=f[i][j]||f[i][j-1];
                }
            }
        }
        return f[n][m];
    }
};
