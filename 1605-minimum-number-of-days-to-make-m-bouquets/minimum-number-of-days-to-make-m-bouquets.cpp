class Solution {
public:
int func(int mid,int k,int m,vector<int>&bloomDay)
{
        int n=bloomDay.size();
        vector<int> temp(n,0);
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=mid) temp[i]=1;
        }
        int cnt=0;
        int l=0;
        int r=0;
        while(r<n)
        {
            if(temp[r]==0) {
                r++;
                l=r;
            }
            else {
                int len=r-l+1;
                if(len==k){
                      
                      cnt++;
                      if(cnt==m) return 1;
                      r++;
                      l=r;
                }
                else
                r++;
                // l=r;
            }
        }
    if(cnt==m) return 1;
    return 0;
        
}
    int minDays(vector<int>& bloomDay, int m, int k) {
       int low=*min_element(bloomDay.begin(),bloomDay.end());
       int high=*max_element(bloomDay.begin(),bloomDay.end());
       int cur=m;
       int ans=INT_MAX;
       while(low<=high)
       {
              int mid=(low+high)/2;
              
              int val=func(mid,k,m,bloomDay);

              if(val==0)
              {
                low=mid+1;
              }
              if(val==1)
              {
                ans=min(ans,mid);
                high=mid-1;
              }
               

       }
       if(ans!=INT_MAX)
       return ans;
       else return -1;
    }
};