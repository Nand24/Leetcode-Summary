class Solution {
public:
void dfs(int sr,int sc,vector<vector<int>>&vis,vector<vector<char>>& grid)
{
    vis[sr][sc]=1;
    int di[]={1,0,0,-1};
    int dj[]={0,-1,1,0};
    for(int i=0;i<4;i++)
    {
        int nr=sr+di[i];
        int nc=sc+dj[i];
        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]=='1')
        {
            dfs(nr,nc,vis,grid);
        }
    }
    return;
}
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
         queue<pair<int,int>> q;
         int count=0;
          for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j])
                {
                    dfs(i,j,vis,grid);
                    count++;
                }
                
            }
        }
        return count;
    }
};