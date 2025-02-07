class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> res(n,0);
        unordered_map<int,int> ballmap; // (ball,color)
        unordered_map<int,int> colormap; // (color,cnt)
        for(int i=0;i<n;i++)
        {
            int color=queries[i][1];
            int ball=queries[i][0];
               if(ballmap.find(ball)!=ballmap.end())
               {
                   int prevcolor=ballmap[ball];
                   colormap[prevcolor]--;
                   if (colormap[prevcolor] == 0) colormap.erase(prevcolor);
               }
               ballmap[ball]=color;
               colormap[color]++;
               res[i]=colormap.size();
        }
        return res;
    }
};