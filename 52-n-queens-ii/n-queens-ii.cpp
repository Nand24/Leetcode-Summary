class Solution {
    public:
        bool issafe(int row, int col, vector<string> board, int n) {
        int duplcol = col;
        int duplrow = row;
        // upper diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        // left
        row = duplrow;
        col = duplcol;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }
        // lower diagonal
        row=duplrow;
        col=duplcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }
    void solve(int n, vector<string>& board, int col,
               vector<vector<string>>& ans) {
        if (col == n ) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (issafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(n, board, col + 1, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
          vector<vector<string>> ans;
        vector<string> board(n,string (n,'.'));
        solve(n,board,0,ans);
        return ans.size();
    }
};