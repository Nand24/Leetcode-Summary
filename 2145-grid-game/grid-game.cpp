class Solution {
public:
    long long  gridGame(vector<vector<int>>& grid) {
        
        long long int firstrowsum=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long int secondrowsum=0;
       long long int n=grid[0].size();
    long long  int minimumsum=LLONG_MAX;
          for( int turnindex=0;turnindex<n;turnindex++)
          {
            firstrowsum-=grid[0][turnindex];
            minimumsum= min(minimumsum,  max(firstrowsum,secondrowsum));
            secondrowsum+=grid[1][turnindex];

          }
          return minimumsum;


    }
};