class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size(),m=matrix[0].size();
        int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
        vector<vector<bool>> use(n,vector<bool>(m));

        for(int i=0,x=0,y=0,d=0;i<n*m;i++){
            ans.push_back(matrix[x][y]);
            use[x][y]=true;

            int tmpx=x+dx[d],tmpy=y+dy[d];
            if(tmpx>=n||tmpx<0||tmpy>=m||tmpy<0||use[tmpx][tmpy])//注意这里判断条件别写错
                d=(d+1)%4;
            x=x+dx[d],y=y+dy[d];
        }

        return ans;
    }
};
