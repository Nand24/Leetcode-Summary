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
        vector<int> temp1,temp2;
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size(),-1),dp2(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(func(0,temp1,dp1), func(0,temp2,dp2) );
    }
};