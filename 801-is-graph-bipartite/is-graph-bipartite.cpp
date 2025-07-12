class Solution {
public:
bool dfs(int node,int colour,vector<vector<int>>&graph,vector<int>&col)
{
    col[node]=colour;
        for(auto it:graph[node])
        {
            if(col[it]==-1)
            {
                if(colour==0) {
                    if(dfs(it,1,graph,col)==false) return false;
                }
                else{
                   if(dfs(it,0,graph,col)==false) return false;
                }
            }
            else if(col[it]==colour) return false;

        }
        return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
       vector<int>col(graph.size(),-1);
       for(int i=0;i<graph.size();i++)
       {
        if(col[i]==-1)
        {
            if(dfs(i,0,graph,col)==false) return false;
        }
       }
       return true;
    }
};