class Solution {
public:
int f(int i,int j,vector<vector<int>>&obstacleGrid,int m,int n,vector<vector<int>>&dp)
{
    if(i==m-1 && j==n-1)
    {
        return 1;
    }
    if(i>=m || j>=n ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int down=0;
    int right=0;
    if(i+1<m && obstacleGrid[i+1][j]!=1)
     down=f(i+1,j,obstacleGrid,m,n,dp);
    if(j+1<n && obstacleGrid[i][j+1]!=1)
     right=f(i,j+1,obstacleGrid,m,n,dp);

    return dp[i][j]=down+right;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
            if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
            if(m==1 && n==1) return 1;
            vector<vector<int>> dp(m,vector<int>(n,-1)); 
        return f(0,0,obstacleGrid,m,n,dp);
    }
};