class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for(auto it: graph[i])
            {
                adj[it].push_back(i);
               // adj[i].push_back(it)
            }
        }

        vector<int> indegree(adj.size(), 0);
        for (int i = 0; i < adj.size(); i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};