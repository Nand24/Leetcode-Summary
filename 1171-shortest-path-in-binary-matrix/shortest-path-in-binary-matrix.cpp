class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int di[]={-1,0,1,-1,1,-1,0,1};
        int dj[]={-1,-1,-1,0,0,1,1,1};
        int rows=grid.size();
        int col=grid[0].size();
        vector<vector<int>> dist(rows,vector<int>(col,INT_MAX));
        dist[0][0]=1;
        queue< pair<int,pair<int,int> > > q;    // {dist,{row,col}}
        q.push({1,{0,0}});
        while(!q.empty())
        {
            auto it=q.front();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nr=r+di[i];
                int nc=c+dj[i];
                if(nr>=0 && nr<rows && nc>=0 && nc<col && grid[nr][nc]==0)
                {
                     if(dis +1 <dist[nr][nc])
                     {
                        dist[nr][nc]=dis+1;
                        q.push({dis+1,{nr,nc}});
                     }
                }
            }
        }
        if(dist[rows-1][col-1]==INT_MAX) return -1;
        return dist[rows-1][col-1];
    }
};