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
    }

    boolean dfs(int x,int y,String word,int k){
        if(k==word.length()) return true;
    }
}
