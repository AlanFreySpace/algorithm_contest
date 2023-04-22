package week5;

public class p79 {
	int m,n;
    boolean[][] flag;//表示格子有没有被用过
    //上下左右四个方位
    int[] dx={0,0,-1,1};
    int[] dy={-1,1,0,0};

    public boolean exist(char[][] board, String word) {
        m=board.length;
        n=board[0].length;
        flag=new boolean[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(j,i,board,word,0)) return true;
            }
        }
        return false;
    }

    boolean dfs(int x,int y,char[][] board,String word,int k){
        if(k==word.length()) return true;
        if(word.charAt(k)!=board[y][x]) return false;

        flag[y][x]=true;
        boolean tmp=false;
        for(int i=0;i<4;i++){
            int tox=x+dx[i],toy=y+dy[i]; 
            if(tox>=0&&tox<n&&toy>=0&&toy<m&&!flag[toy][tox]){
                if(dfs(tox,toy,board,word,k+1)) return true;
            }
        }
        flag[y][x]=false;
        return false;
    }
}
