class Solution {
public:
    int n, m;
    vector<vector<char>> board;
    int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

    void solve(vector<vector<char>>& _board) {
        board = _board;
        n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0);
            }
            if (board[i][m - 1] == 'O') {
                dfs(i, m - 1);
            }
        }

        for (int i = 1; i < m - 1; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i);
            }
            if (board[n - 1][i] == 'O') {
                dfs(n - 1, i);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }

        _board = board;
    }

    void dfs(int x, int y) {
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int tox = x + dx[i], toy = y + dy[i];
            if (tox >= 0 && tox < n && toy >= 0 && toy < m && board[tox][toy] == 'O') {
                dfs(tox, toy);
            }
        }
    }

};