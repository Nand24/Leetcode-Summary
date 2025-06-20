class Solution {
public:
    int maxDistance(string s, int k) {
       int ans=0;
        int n=0; int S=0; int e=0; int w=0;
        for(int i=0;i<s.size();i++)
        {
   
            if(s[i]=='N')
            {
                n++;
            }
             if(s[i]=='S')
            {
                S++;
            }
             if(s[i]=='E')
            {
                e++;
            }
             if(s[i]=='W')
            {
                w++;
            }              
            int t1=min({n,S,k});
            int t2=min({e,w,k-t1});
            ans= max(ans,(abs(n-S)+2*t1)+(abs(e-w)+t2*2));
        }
        return ans;
    }
};