package week4;

public class p52 {
	//注意不需要使用usey,因为y一定是单调递增不同的
	boolean[] usex,usexy,useyx;
    int ans=0;

    public int totalNQueens(int n) {
        usex=new boolean[n];
        usexy=new boolean[2*n-1];
        useyx=new boolean[2*n-1];
        dfs(n,0);
        return ans;
    }

    void dfs(int n,int y){
        if(y==n) ans++;

        for(int x=0;x<n;x++){
            if(!usex[x]&&!usexy[y-x+n-1]&&!useyx[x+y]){
                usex[x]=usexy[y-x+n-1]=useyx[x+y]=true;
                dfs(n,y+1);
                usex[x]=usexy[y-x+n-1]=useyx[x+y]=false;
            }
        }
    }
}
