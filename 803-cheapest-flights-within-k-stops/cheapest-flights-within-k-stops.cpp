class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue< tuple<int,int,int>> q;   // stops,node,price;
        q.push({0,src,0});
        while (!q.empty()) {
            auto [stops,node,price] = q.front();
            q.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int cost=it.second;
                if(price+cost< dist[adjnode] && stops+1<=k+1)
                {
                    dist[adjnode]=price+cost;
                    q.push({stops+1,adjnode,price+cost});
                }
                
            }
        }
        if(dist[dst]==INT_MAX)
        return -1;
        else return dist[dst];
    }
};