package week5;

public class p79 {
	int m,n;
    //上下左右四个方位
    int[] dx={0,0,-1,1};
    int[] dy={-1,1,0,0};

    public boolean exist(char[][] board, String word) {
        m=board.length;
        n=board[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(j,i,board,word,0)) return true;
            }
        }
        return false;
    }

    boolean dfs(int x,int y,char[][] board,String word,int k){
        if(word.charAt(k)!=board[y][x]) return false;
        if(k==word.length()-1) return true;

        char t=board[y][x];
        board[y][x]='.';//注意用这种方法表示格子被占用很巧妙
        for(int i=0;i<4;i++){
            int tox=x+dx[i],toy=y+dy[i]; 
            if(tox>=0&&tox<n&&toy>=0&&toy<m&&board[toy][tox]!='.'){
                if(dfs(tox,toy,board,word,k+1)) return true;
            }
        }
        board[y][x]=t;
        return false;
    }
}
