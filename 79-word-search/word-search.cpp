class Solution {
public:
void dfs(int sr,int sc,vector<vector<char>>& board,vector<vector<int>>&vis,int idx,string&word,bool&found)
{
    if(idx==word.size()){
        found=true;
        return;
    }
  //  if(found) return;
    vis[sr][sc]=1;
    int di[]={1,0,0,-1};
    int dj[]={0,-1,1,0};
    for(int i=0;i<4;i++)
    {
        int nr=sr+di[i];
        int nc=sc+dj[i];
        if(nr>=0 && nr <board.size() && nc>=0 && nc<board[0].size() && !vis[nr][nc] && idx<word.size() &&board[nr][nc]==word[idx])
        {
        
            dfs(nr,nc,board,vis,idx+1,word,found);
        }
    }
    vis[sr][sc]=0;
    return;
}
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
          bool found=false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0]){
                       dfs(i,j,board,vis,1,word,found);
                }
            }
        }
  return found;
        
    }
};