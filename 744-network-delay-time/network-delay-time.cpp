class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<  pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[0]=-1;
        dist[k]=0;
        priority_queue< pair<int,int> , vector< pair<int,int> > , greater < pair<int,int> > >pq; // wt,node;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            for(auto it:adj[node])
            {
                int cost=it.second;
                int adjnode=it.first;
                if(cost+wt < dist[adjnode])
                {
                    dist[adjnode]=cost+wt;
                    pq.push({cost+wt,adjnode});
                }
            }
        }
        if(* max_element(dist.begin(),dist.end()) ==INT_MAX)
        return-1 ;
        else 
        return * max_element(dist.begin(),dist.end());
    }
};