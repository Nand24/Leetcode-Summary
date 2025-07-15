class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long, long>>> adj(n);
        long long mod=1e9+7;
        for (int i = 0; i < roads.size(); i++) {
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n,0);
        ways[0]=1;
        dist[0] = 0;
        priority_queue<pair<long, long>, vector<pair<long, long>>,
                       greater<pair<long, long>>>
            pq; // wt,node;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto it = pq.top();
            long long wt = it.first;
            long long node = it.second;
             pq.pop();
            for (auto it : adj[node]) {
                long long cost = it.second;
                long long adjnode = it.first;
                if (cost + wt < dist[adjnode]) {
                    dist[adjnode] = cost + wt;
                    ways[adjnode]=ways[node]; // first time reaching adjnode so jitne tareeke node tk pauchne ke hai utne hi adjnode pauchne ke honge
                    pq.push({cost + wt, adjnode});
                }
                else  if(cost+wt==dist[adjnode])
                {
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};