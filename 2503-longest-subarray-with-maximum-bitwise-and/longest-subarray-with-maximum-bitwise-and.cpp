class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int len=INT_MIN;
        while(r<nums.size())
        {
            if(nums[r]==maxi)
             len=max(len,r-l+1);
             else l=r+1;
             r++;
        }
        return len;
    }
};