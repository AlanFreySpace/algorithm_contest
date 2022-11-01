package week3;

public class p36 {
	public boolean isValidSudoku(char[][] board) {
        boolean flag[]=new boolean[10];

        for(int i=0;i<9;i++){
            toFalse(flag);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    if(flag[num]) return false;
                    flag[num]=true;
                }
            }
        }

        for(int i=0;i<9;i++){
            toFalse(flag);
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    int num=board[j][i]-'0';
                    if(flag[num]) return false;
                    flag[num]=true;
                }
            }
        }

        for(int i=0;i+3<=9;i+=3){
            for(int j=0;j+3<=9;j+=3){
                toFalse(flag);
                for(int u=0;u<3;u++){
                    for(int v=0;v<3;v++){
                        if(board[i+u][j+v]!='.'){
                            int num=board[i+u][j+v]-'0';
                            if(flag[num]) return false;
                            flag[num]=true;
                        }
                    }
                }
            }
        }

        return true;
    }

    void toFalse(boolean[] flag){
        for(int i=0;i<flag.length;i++) flag[i]=false;
    }
}
