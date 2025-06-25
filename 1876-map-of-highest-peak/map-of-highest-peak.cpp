class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
             vector<vector<int>> ans=isWater;
         queue< pair< pair<int,int>,int>> q; 
         vector<vector<int>> vis=isWater;
         int di[]={1,0,0,-1};
         int dj[]={0,-1,1,0};//DLRU
         for(int i=0;i<isWater.size();i++)
         {
            for(int j=0;j<isWater[0].size();j++)
            {
                if(isWater[i][j]==1) {q.push({{i,j,},0}); ans[i][j]=0;}
                vis[i][j]=0;
            }
         }
         while(!q.empty())
         {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist=q.front().second;
            ans[r][c]=dist;
            q.pop();
                for(int i=0;i<4;i++)
                {
                     int nr=r+di[i];
                     int nc=c+dj[i];
                     if(nr>=0 && nr<isWater.size() && nc>=0 && nc<isWater[0].size() && vis[nr][nc]!=1 && isWater[nr][nc]!=1)
                     {
                           q.push({{nr,nc},dist+1});
                           vis[nr][nc]=1;
                     }
                }
         }
         return ans;
    }
    
};