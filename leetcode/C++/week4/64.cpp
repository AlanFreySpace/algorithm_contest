class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        vector<vector<int>> f(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!i&&!j) f[i][j]=g[i][j];
                else{
                    f[i][j]=INT_MAX;
                    if(i) f[i][j]=f[i-1][j]+g[i][j];
                    if(j) f[i][j]=min(f[i][j],f[i][j-1]+g[i][j]);
                }
            }
        }

        return f[m-1][n-1];
    }
};
