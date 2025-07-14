class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        int rows = heights.size();
        int col = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(col, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        // queue< pair<int,pair<int,int> > > pq;    // {dist,{row,col}}
        q.push({0, {0, 0}});
        while (!q.empty()) {
            auto it = q.top();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
             if(r==rows-1 && c==col-1) return dist[r][c];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + di[i];
                int nc = c + dj[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < col) {

                    int neweffort = abs(heights[nr][nc] - heights[r][c]);
                    if (max(neweffort, dis) < dist[nr][nc]) {
                        
                        dist[nr][nc]=max(neweffort, dis);
                         q.push({max(neweffort, dis),{nr, nc}});
                    }
                }
            }
        }
            return 0;
    }

 };