class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int maxsum=0;
        int sum=0;
        map<int,int> mpp;
        while(r<nums.size()){
            sum+=nums[r];
            mpp[nums[r]]++;
            while(mpp[nums[r]]!=1)
            {
                sum-=nums[l];
                mpp[nums[l]]--;
                l++;
            }
            maxsum=max(maxsum,sum);
            r++;
        }
        return maxsum;
    }
};