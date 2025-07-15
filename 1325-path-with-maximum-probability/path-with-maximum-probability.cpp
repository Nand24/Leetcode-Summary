class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector< pair<int,double>> >adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0]; 
            int v=edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        vector<double> dist(n,0.0);
        dist[start_node]=1.0;
        priority_queue< pair<double,int> > pq;
        pq.push({1.0,start_node});   // prob,start
        while(!pq.empty())
        {
            auto it=pq.top();
            double prob=it.first;
            int node=it.second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                double p=it.second;
                if(p*prob > dist[adjnode])
                {
                    dist[adjnode]=p*prob;
                    pq.push({p*prob,adjnode});
                }
            }
        }
        return dist[end_node];
    }
};