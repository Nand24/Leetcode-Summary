class Solution {
public:
int func(int k,vector<int>&piles,int h)
{
    int ans=0;
    for(int i=0;i<piles.size();i++)
    {
        ans+=ceil(double(piles[i])/k);
        if(ans>h) return 2;

    }
    if(ans<=h) return 1;

return -1;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1; // minimum no of bananas per hour
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=(low+high)/2;

            int val=func(mid,piles,h);

            if(val==1) high=mid-1;
            if(val==2) low=mid+1;
       
           
        }
        return low;
    }
};