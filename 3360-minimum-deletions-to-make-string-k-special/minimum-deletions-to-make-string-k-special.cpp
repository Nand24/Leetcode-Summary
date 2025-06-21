class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto ch: word)
        {
            freq[ch-'a']++;
        }
        vector<int> nonzero;
        for(auto it:freq)
        {
            if(it>0) nonzero.push_back(it);
        }
        sort(nonzero.begin(),nonzero.end());
        int max_f=*max_element(nonzero.begin(),nonzero.end());
        int ans=INT_MAX;
        // maksad ye hai ki ek esa m dhundhan jisse har element ki frequency [m,m+k] ho aur vo minimum ops le
        // m ki possible values kya hain freq ki non zero values ie 1----> max_f
        for(int m=1;m<=max_f;m++)
        {
            int cost=0;
            for(auto f:nonzero)
            {
                if(f<m)
                {
                    cost+=f;
                }
                else if(f>m+k)
                {
                    cost+=f-(m+k);
                }
            }
            ans=min(ans,cost);
        }
        
        return ans;
    }
};