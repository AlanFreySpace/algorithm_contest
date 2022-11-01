package week3;

public class p37 {
	boolean row[][]=new boolean[9][9];
    boolean col[][]=new boolean[9][9];
    boolean cell[][][]=new boolean[3][3][9];

    public void solveSudoku(char[][] board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'1';
                    row[i][num]=true;
                    col[j][num]=true;
                    cell[i/3][j/3][num]=true;
                }
            }
        }

        dfs(board,0,0);
    }

    boolean dfs(char[][] board,int x,int y){
        if(y==9) return dfs(board,x+1,0);
        if(x==9) return true;

        if(board[x][y]!='.') return dfs(board,x,y+1);
        for(int i=0;i<9;i++){
            if(!row[x][i]&&!col[y][i]&&!cell[x/3][y/3][i]){
                row[x][i]=true;
                col[y][i]=true;
                cell[x/3][y/3][i]=true;
                board[x][y]=(char)(i+'1');
                if(dfs(board,x,y+1)) return true;
                row[x][i]=false;
                col[y][i]=false;
                cell[x/3][y/3][i]=false;
                board[x][y]='.';
            }
        }

        return false;
    }
}
