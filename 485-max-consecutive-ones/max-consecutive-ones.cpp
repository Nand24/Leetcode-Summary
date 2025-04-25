class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l,r=0; int n=nums.size();
        int maxlen=0;
        while(r<n)
        {
            if(nums[r]==0)
            { 
                l=r+1;
                r++;
            }  
            else{  
            int currlen=r-l+1;
            maxlen=max(maxlen,currlen);
            r++;
            }
        }
        return maxlen;
    }
};