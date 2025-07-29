class Solution {
public:
    int searchind(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]==nums[low] && nums[mid]==nums[high])
            {
                low++;
            }
            
           else if(nums[mid]>=nums[low])
            {
                // left sorted
                if(target>=nums[low] && target<=nums[mid])
                {
                    high=mid-1;
                }
                else low=mid+1;
            }
            else{
                // right sorted
                    if(target>=nums[mid] && target<=nums[high])
                {
                    low=mid+1;
                }
                else high=mid-1;
            }

        }
        return -1;
 }
    bool search(vector<int>& nums, int target) {
   if(searchind(nums,target)==-1) return false;
   else return true;
    }
};