class Solution {
public:
int func(int index,vector<int>&nums,vector<int>&dp)
{
    if(index>=nums.size()) return 0;
    if(dp[index]!=-1) return dp[index];
    int pick=nums[index]+func(index+2,nums,dp);
    int notpick=0+func(index+1,nums,dp);
    return dp[index]=max(pick,notpick);

}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return func(0,nums,dp);
    }
};