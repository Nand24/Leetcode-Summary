class Solution {
public:
void dfs(int sr,int sc,vector<vector<int>>&vis,vector<vector<int>>&grid)
{
    vis[sr][sc]=1;
    int di[]={1,0,0,-1};
    int dj[]={0,-1,1,0};
    for(int i=0;i<4;i++)
    {
        int nr=sr+di[i];
        int nc=sc+dj[i];
        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] &&grid[nr][nc]==1)
        {
            dfs(nr,nc,vis,grid);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0]==1)
            dfs(i,0,vis,grid);
            if(grid[i][col-1]==1)
            dfs(i,col-1,vis,grid);
        }
         for(int j=0;j<grid[0].size();j++)
        {
            if(grid[0][j]==1)
            dfs(0,j,vis,grid);
            if(grid[row-1][j]==1)
            dfs(row-1,j,vis,grid);
        }
        int cnt=0;
for(int i=0;i<grid.size();i++) for(int j=0;j<grid[0].size();j++) if(grid[i][j]==1 &&!vis[i][j]) cnt++;
return cnt;
    }
};