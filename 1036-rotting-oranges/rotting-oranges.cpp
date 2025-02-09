class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> isrotten;
        int r = grid.size();
        int c = grid[0].size();
        int visited[r][c];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    isrotten.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else
                    visited[i][j] = 0;
            }
        }
        int time = 0;

        while (!isrotten.empty()) {
            pair<pair<int, int>, int> p = isrotten.front();
            isrotten.pop();
            int row = p.first.first;
            int col = p.first.second;
            int t = p.second;
            time = max(t, time);
            int delrow[] = {1, 0, 0, -1}; // DLRU
            int delcol[] = {0, -1, 1, 0}; // DLRU
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c &&
                    grid[nrow][ncol] == 1 && visited[nrow][ncol] !=2 ) {
                    visited[nrow][ncol] = 2;
                    isrotten.push({{nrow, ncol}, t + 1});
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                  if(grid[i][j]==1 && visited[i][j]==0)
                  {
                    return -1;
                  }
            }
        }
        return time;
    }
};