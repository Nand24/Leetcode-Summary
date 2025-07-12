class Solution {
public:
  bool topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(res.size()<V) return false;
        else return true ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      return topoSort(numCourses,prerequisites);
    }
};