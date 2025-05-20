class Solution {
public:
void f(int sr,int sc,int&startcolor,vector<vector<int>>&image,int &color)
{
    image[sr][sc]=color;
    int delrow[]={1,0,0,-1};//DLRU
    int delcol[]={0,-1,1,0};//DLRU
    for(int i=0;i<4;i++)
    {
        int nr=sr+delrow[i];
        int nc=sc+delcol[i];
            if(nr>=0 && nr<image.size()  && nc>=0 && nc<image[0].size()){
            if(image[nr][nc]==startcolor  && image[nr][nc]!=color )
            {
    
                f(nr,nc,startcolor,image,color);
            }
            }
     }
    
    return;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> res;
        int startcol=image[sr][sc];
        f(sr,sc,startcol,image,color);
        return image;
    }
};