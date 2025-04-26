class Solution {
public:
bool func(vector<int>&nums,int i,int target,vector<vector<int>>&dp)
{
    if(target==0) return true;
    if(i==0) return (nums[i]==target);
    if(dp[i][target]!=-1) return dp[i][target];
     bool take=false;
    if(target>=nums[i])
    {
         take=func(nums,i-1,target-nums[i],dp);
    
    } 
    bool not_take=func(nums,i-1,target,dp);

    return dp[i][target]=take||not_take;
}
    bool canPartition(vector<int>& nums) {
        int target=0; int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            target+=nums[i];
        }
        if(target%2!=0) return false;
        else
        {
          vector<vector<int>>dp(n,vector<int>((target/2)+1,-1));
        return func(nums,n-1,target/2,dp);

        }
    }
};