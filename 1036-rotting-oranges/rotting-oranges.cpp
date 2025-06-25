class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue < pair< pair<int,int>, int>> q;
        vector<vector<int>> vis = grid;
        int rows = grid.size();
        int cols = grid[0].size();
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        int time = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(t, time);
            for (int i = 0; i < 4; i++) {
                int nr = r + di[i];
                int nc = c + dj[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    grid[nr][nc] == 1 && vis[nr][nc] != 2) {
                q.push({{nr, nc},t+1});
                        vis[nr][nc] = 2;
            }
                }
            }
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    if(grid[i][j]==1 && vis[i][j]!=2)
                    {
                        return -1;
                    }
                }
            }
            return time;
        }
    };