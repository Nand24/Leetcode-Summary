class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int maxlen=0;
        int bit_mask=0;
        while(r<nums.size()){
            
            if((nums[r] & bit_mask) ==0){
              bit_mask=nums[r] | bit_mask;
                maxlen=max(maxlen,r-l+1);
               r++;
            } 
            else{
                bit_mask=bit_mask^nums[l];
                l++;
            }
          
        }
        return maxlen;
    }
};