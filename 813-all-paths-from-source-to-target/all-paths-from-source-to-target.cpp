class Solution {
public:
void dfs(int node,int target,vector<int>&temp,vector<vector<int>>&graph,vector<vector<int>>&res)
{
    if(node==target)
    {
        res.push_back(temp);
        return;
    }

    for(auto it:graph[node])
    {
        temp.push_back(it);
         dfs(it,target,temp,graph,res);
         temp.pop_back();
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>> res;
       vector<int> temp;
       int n=graph.size();
       temp.push_back(0);
       dfs(0,n-1,temp,graph,res);
       return res;
    }
};