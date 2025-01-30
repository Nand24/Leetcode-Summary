class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // if(nums.size()==1)
        // {
        //     if(nums[0]<0)
        //     {
        //         return -1;
        //     }
        //     else
        //     {
        //         return nums[0];
        //     }
        // }
        int maxending=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
           
           maxending=max(maxending+nums[i],nums[i]);
        //    if(maxending<0)
        //    {
        //          res=max(res,maxending);
        //    }
        //    else if(maxending>=0){
           res=max(res,maxending);
        //    }
        }
        return res;
    }
};