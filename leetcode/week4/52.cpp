class Solution {
public:
    int n,ans=0;
    vector<bool> col,dg,rdg;

    int totalNQueens(int _n) {
        n=_n;
        col=vector<bool>(n);
        dg=rdg=vector<bool>(2*n);
        dfs(0);
        return ans;
    }

    void dfs(int u){
        if(u==n){
            ans++;
            return;
        }

        for(int i=0;i<n;i++){
            if(!col[i]&&!dg[i-u+n]&&!rdg[i+u]){
                col[i]=dg[i-u+n]=rdg[i+u]=true;
                dfs(u+1);
                col[i]=dg[i-u+n]=rdg[i+u]=false;
            }
        }
    }
};
