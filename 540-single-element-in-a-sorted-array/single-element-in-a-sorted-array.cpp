class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low=0;
        int high=nums.size()-1;
        int n=nums.size();
        int ans=0;
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid-1>=0 && nums[mid]==nums[mid-1])
            {
                if((mid-1)%2==0) {
                    //left half eliminate
                    low=mid+1;
                }
                else{
                    high=mid-1;
                    //eliminate right half
                }

            }
            if(mid+1<n && nums[mid]==nums[mid+1])
            {
                if((mid+1)%2==0){
                    //eliminate right half
                    high=mid-1;
                }
                else{
                    //eliminate left half
                    low=mid+1;
                }
            }
            
           if(mid-1>=0 && mid+1<n &&nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            ans=mid;
            break;
           }

        }
return nums[ans];
    }
};