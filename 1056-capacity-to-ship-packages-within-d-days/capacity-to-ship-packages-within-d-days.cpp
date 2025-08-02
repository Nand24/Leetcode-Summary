class Solution {
public:
int func(int cap,vector<int>&weights,int days)
{
    int daycnt=1;
    int load=0;
    for(int i=0;i<weights.size();i++)
    {
          
          if(load +weights[i]>cap) {
            daycnt++; 
            load=weights[i];
            }
            else load+=weights[i];


    }
return (daycnt<=days);
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int total=0;
        for(int i=0;i<weights.size();i++) total+=weights[i];
        int high=total;
        while(low<=high)
        {
            int mid=(low+high)/2;
                
            int val=func(mid,weights,days);
            if(val==1)
            {
             
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};