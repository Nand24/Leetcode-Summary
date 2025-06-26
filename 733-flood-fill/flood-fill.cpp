class Solution {
public:
void    f(int sr, int sc, int&initialclr, vector<vector<int>>& vis,
      vector<vector<int>>& image, int &finalclr,vector<vector<int>>& res) {
        vis[sr][sc] = 1;
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nr=sr+di[i]; int nc=sc+dj[i];
            if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && vis[nr][nc]==0 &&image[nr][nc]==initialclr)
            {
                res[nr][nc]=finalclr;
                f(nr,nc,initialclr,vis,image,finalclr,res);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> res = image;
        int intialclr = image[sr][sc];
        res[sr][sc]=color;
        vector<vector<int>> vis = image;
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[0].size(); j++)
                vis[i][j] = 0;
        }
        f(sr, sc, image[sr][sc], vis, image, color,res);
        return res;
    }
};