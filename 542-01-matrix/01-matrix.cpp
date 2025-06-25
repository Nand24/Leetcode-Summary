class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         vector<vector<int>> ans=mat;
         queue< pair< pair<int,int>,int>> q; 
         vector<vector<int>> vis=mat;
         int di[]={1,0,0,-1};
         int dj[]={0,-1,1,0};//DLRU
         for(int i=0;i<mat.size();i++)
         {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0) {q.push({{i,j,},0}); ans[i][j]=0;}
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
                     if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && vis[nr][nc]!=1 && mat[nr][nc]!=0)
                     {
                           q.push({{nr,nc},dist+1});
                           vis[nr][nc]=1;
                     }
                }
         }
         return ans;
    }
};