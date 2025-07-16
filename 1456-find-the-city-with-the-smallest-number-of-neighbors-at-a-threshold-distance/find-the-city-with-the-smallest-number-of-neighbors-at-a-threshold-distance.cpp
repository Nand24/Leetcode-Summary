class Solution {
public:

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
         {
            cost[it[0]][it[1]]=it[2];
            cost[it[1]][it[0]]=it[2];
         }
         for(int k=0;k<n;k++)
         {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(cost[i][k]!=INT_MAX && cost[k][j]!=INT_MAX)
                    {
                        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                    }
                }
            }
         }
         
         vector<int> r(n,0);
         for(int i=0;i<n;i++)
            {
                int cnt=0;
                for(int j=0;j<n;j++)
                {
                    if(cost[i][j]!=INT_MAX && cost[i][j]<=distanceThreshold && i!=j)
                    {
                        cnt++;
                    }
                }
                r[i]=cnt;
            }
            int m=*min_element(r.begin(),r.end());
            int ans=-1;
            for(int i=0;i<n;i++)
            {
                if(r[i]==m)
                {
                    ans=max(ans,i);
                }
            }
            return ans;
    }
};