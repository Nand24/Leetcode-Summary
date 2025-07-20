class Solution {
public:
int func(vector<int>&nums,int k){
    if(k<0) return 0;
        int l=0;
        int r=0;
        int cnt=0;
        int odd=0;
        while(r<nums.size())
        {
            if(nums[r]%2==1) odd++;
            while(odd>k)
            {
                if(nums[l]%2==1) odd--;    
                l++;
            }

            cnt+=(r-l+1);
            r++;
        }
return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
     return func(nums,k) -func(nums,k-1);
    }
};