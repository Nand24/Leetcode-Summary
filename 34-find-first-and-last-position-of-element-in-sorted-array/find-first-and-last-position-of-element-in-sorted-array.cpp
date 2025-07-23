class Solution {
public:
int ub(vector<int>&arr,int n,int x)
{
    int ans=n;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>x)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int lb(vector<int>&arr,int n, int x)
{
    int ans=-1;
     int low=0;
     int high=n-1;
     while(low<=high)
     {
        int mid=(low+high)/2;
        if(arr[mid]>=x)
        {
           ans=mid;
           high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lower=lb(nums,n,target);
        int upper=ub(nums,n,target) -1;
         if( lower==-1 ||  nums[lower]!=target ) return{-1,-1};
         else return {lower,upper};
    }
};