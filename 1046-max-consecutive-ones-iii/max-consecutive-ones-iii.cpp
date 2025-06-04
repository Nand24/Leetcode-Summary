class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxlen=INT_MIN;
        int zeroes=0;
        while(r<nums.size())
        {
            if(nums[r]==0) zeroes++;
            if(zeroes<=k)
            {
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }
            else{
                if(nums[l]==0) zeroes--;
                l++;
            }
            r++;
        }
        if(maxlen!=INT_MIN)
            return maxlen;
        else 
            return 0;
    }
};
