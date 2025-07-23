class Solution {
public:
int last_occur(vector<int>&nums,int n,int target)
{
    int low=0;
    int high=n-1;
    int last=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(nums[mid]==target)
        {
            last=mid;
            low=mid+1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return last;
}
int first_occur(vector<int>&nums,int n,int target)
{
    int low=0;
    int high=n-1;
    int first=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(nums[mid]==target)
        {
            first=mid;
            high=mid-1;
        }
       else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first_occur(nums,nums.size(),target),last_occur(nums,nums.size(),target)};
    }
};