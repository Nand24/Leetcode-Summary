class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
         vector<int>rowcnt(grid.size(),0);
         vector<int> colcnt(grid[0].size(),0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j])

                {
                    rowcnt[i]++;
                    colcnt[j]++;
                }
            }
        }
        int cnt=0;
         for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j])

                {
                    cnt+= rowcnt[i] >1 || colcnt[j]>1;
                }
            }
        }
     
        return cnt;
    }
};