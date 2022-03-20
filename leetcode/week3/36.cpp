class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[9];
        //ÅÐ¶ÏÐÐ
        for(int i=0;i<9;i++){
            memset(st,0,sizeof(st));
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int t=board[i][j]-'1';
                    if(st[t]) return false;
                    st[t]=true;
                }
            }
        }
        //ÅÐ¶ÏÁÐ
        for(int i=0;i<9;i++){
            memset(st,0,sizeof(st));
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    int t=board[j][i]-'1';
                    if(st[t]) return false;
                    st[t]=true;
                }
            }
        }
        //ÅÐ¶ÏÐ¡¾Å¹¬¸ñ
        for(int i=0;i+3<=9;i+=3){
            for(int j=0;j+3<=9;j+=3){
                memset(st,0,sizeof(st));
                for(int u=0;u<3;u++){
                    for(int v=0;v<3;v++){
                        if(board[i+u][j+v]!='.'){
                            int t=board[i+u][j+v]-'1';
                            if(st[t]) return false;
                            st[t]=true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
