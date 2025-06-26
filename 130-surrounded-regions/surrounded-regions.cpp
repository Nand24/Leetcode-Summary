class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& vis,
             vector<vector<char>>& board) {
        vis[sr][sc] = 1;
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nr = sr + di[i];
            int nc = sc + dj[i];
            if (nr >=0 && nr < board.size()  && nc >= 0 &&
                nc < board[0].size() && !vis[nr][nc] &&
                board[nr][nc] == 'O') {
                dfs(nr, nc, vis, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),
                                 vector<int>(board[0].size(), 0));
        int rows = board.size();
        int col = board[0].size();
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O')
               dfs(i,0,vis,board);
            if (board[i][col - 1]=='O')
                dfs(i,col-1,vis,board);
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O')
                 dfs(0,j,vis,board);
            if (board[rows - 1][j] == 'O')
                dfs(rows-1,j,vis,board);
        }
for(int i=0;i<rows;i++) for(int j=0;j<col;j++) if(vis[i][j]==0) board[i][j]='X';
    }
};