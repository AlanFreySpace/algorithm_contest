class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<string> path;
    vector<bool> col,dg,rdg;
    vector<vector<string>> solveNQueens(int _n) {
        n=_n;
        path=vector<string>(n,string(n,'.'));
        col=vector<bool>(n);
        dg=rdg=vector<bool>(2*n);
        dfs(0);
        return ans;
    }
    //尝试向u行i列中添加皇后
    void dfs(int u){
        if(u==n){
            ans.emplace_back(path);
            return;
        }

        for(int i=0;i<n;i++){
            if(!col[i]&&!dg[i-u+n]&&!rdg[i+u]){
                path[u][i]='Q';
                col[i]=dg[i-u+n]=rdg[i+u]=true;
                dfs(u+1);
                col[i]=dg[i-u+n]=rdg[i+u]=false;
                path[u][i]='.';
            }
        }
    }
};
