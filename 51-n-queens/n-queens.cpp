class Solution {
public:
    void solve(int n, vector<string>& board, int col, 
               vector<vector<string>>& ans, vector<int>& left, 
               vector<int>& upper, vector<int>& lower) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (left[row] == 0 && upper[n - 1 + row - col] == 0 && lower[row + col] == 0) {
                board[row][col] = 'Q';
                left[row] = 1;
                upper[n - 1 + row - col] = 1;
                lower[row + col] = 1;

                solve(n, board, col + 1, ans, left, upper, lower);

                board[row][col] = '.';  
                left[row] = 0;
                upper[n - 1 + row - col] = 0;
                lower[row + col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftrow(n, 0);  
        vector<int> upper(2 * n - 1, 0);
        vector<int> lower(2 * n - 1, 0);

        solve(n, board, 0, ans, leftrow, upper, lower);  
        return ans;
    }
};
