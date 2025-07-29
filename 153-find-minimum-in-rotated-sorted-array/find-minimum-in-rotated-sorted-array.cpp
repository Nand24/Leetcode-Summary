class Solution {
public:
    int findMin(vector<int>& nums) {
           int low=0;
        int n=nums.size();
        int high=n-1;
        int min_ele=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;

            // if(nums[mid]==target)
            // {
            //     return mid;
            // }
            
            if(nums[mid]>=nums[low])
            {
                // left sorted
                min_ele=min(min_ele,nums[low]);
                low=mid+1;
                // if(target>=nums[low] && target<=nums[mid])
                // {
                //     high=mid-1;
                // }
                // else low=mid+1;
            }
            else{
                // right sorted
                 min_ele=min(min_ele,nums[mid]);
                 high=mid-1;
                //     if(target>=nums[mid] && target<=nums[high])
                // {
                //     low=mid+1;
                // }
                // else high=mid-1;
            }

        }
        return min_ele;
    }
};