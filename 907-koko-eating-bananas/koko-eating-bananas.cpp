class Solution {
public:
void BS(int low,int high,vector<int>&piles,int h,int &ans)
{
    if(low>high) return;
    int mid=(low+high)/2;
   long long int temp=0;
    for(int i=0;i<piles.size();i++)
    {
       temp+=ceil((double)(piles[i])/mid);
    }
if(temp<=h)
{
    ans=min(ans,mid);
    BS(low,mid-1,piles,h,ans);
}
else
{
    BS(mid+1,high,piles,h,ans);
}
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=INT_MAX;
        int high=*max_element(piles.begin(),piles.end());
  BS(1,high,piles,h,ans);
  return ans;      
    }
};