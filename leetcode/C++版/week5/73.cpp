class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int r0=1,c0=1;

        for(int i=0;i<m;i++)
            if(!matrix[0][i]){
                r0=0;
                break;
            }

        for(int i=0;i<n;i++)
            if(!matrix[i][0]){
                c0=0;
                break;
            }

        for(int i=1;i<m;i++)
            for(int j=0;j<n;j++)
                if(!matrix[j][i]){
                    matrix[0][i]=0;
                    break;
                }

        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                if(!matrix[i][j]){
                    matrix[i][0]=0;
                    break;
                }

        for(int i=1;i<m;i++)
            if(!matrix[0][i])
                for(int j=1;j<n;j++) matrix[j][i]=0;

        for(int i=1;i<n;i++)
            if(!matrix[i][0])
                for(int j=1;j<m;j++) matrix[i][j]=0;

        if(!r0) for(int i=0;i<m;i++) matrix[0][i]=0;
        if(!c0) for(int i=0;i<n;i++) matrix[i][0]=0;
    }
};
