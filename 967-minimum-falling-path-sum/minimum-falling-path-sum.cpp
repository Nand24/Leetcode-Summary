class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int up = matrix[i][j] + dp[i - 1][j];
                int leftdig = matrix[i][j];
                int rightdig = matrix[i][j];
                if (j - 1 >=0)
                    leftdig += dp[i - 1][j - 1];
                    else leftdig=1e9;
                if (j + 1 < m)
                    rightdig += dp[i - 1][j + 1];
                     else rightdig=1e9;
                dp[i][j] = min({up, leftdig, rightdig});
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};