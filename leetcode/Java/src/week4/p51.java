package week4;

import java.util.ArrayList;
import java.util.List;

public class p51 {
	List<List<String>> ans=new ArrayList<>();
    char[][] path;
    //注意不需要使用usey,因为y一定是单调递增不同的
    boolean[] usex,usexy,useyx;

    public List<List<String>> solveNQueens(int n) {
        usex=new boolean[n];
        usexy=new boolean[2*n-1];
        useyx=new boolean[2*n-1];
        path=new char[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) path[i][j]='.';
        dfs(n,0);
        return ans;
    }

    void dfs(int n,int y){
        if(y==n){
        	//应该注意Java中对字符数组和字符串的操作应该怎样进行
            List<String> list=new ArrayList<>();
            for(int i=0;i<n;i++){
                String tmp=new String(path[i]);
                list.add(tmp);
            }
            ans.add(list);
        }
        for(int x=0;x<n;x++){
            if(!usex[x]&&!usexy[y-x+n-1]&&!useyx[x+y]){
                path[y][x]='Q';
                usex[x]=usexy[y-x+n-1]=useyx[x+y]=true;
                dfs(n,y+1);
                usex[x]=usexy[y-x+n-1]=useyx[x+y]=false;
                path[y][x]='.';
            }
        }
    }
}
