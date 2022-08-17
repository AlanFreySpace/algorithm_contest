class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        vector<vector<int>> f(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!g[i][j]){
                    if(!i&&!j) f[i][j]=1;
                    else{
                        if(i) f[i][j]+=f[i-1][j];
                        if(j) f[i][j]+=f[i][j-1];
                    }
                }
            }
        }

        return f[m-1][n-1];
    }
};
