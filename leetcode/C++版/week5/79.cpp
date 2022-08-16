class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(dfs(board,word,i,j,0)) return true;
        return false;
    }

    int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};

    bool dfs(vector<vector<char>>& board,string& word,int x,int y,int u){
        if(board[x][y]!=word[u]) return false;//剪枝返回
        if(u==word.size()-1) return true;

        char t=board[x][y];
        board[x][y]='.';
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<board.size()&&b>=0&&b<board[0].size()&&board[a][b]!='.')
                if(dfs(board,word,a,b,u+1)) return true;//直接返回 无需恢复现场
        }
        board[x][y]=t;//恢复现场
        return false;
    }
};
