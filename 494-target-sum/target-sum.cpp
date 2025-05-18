class Solution {
public:
int f(int index,int target,vector<int>&nums)
{
    if(index==nums.size()){
    if(target==0)
    {
         return 1;
    }
    return 0;
    }
    int ch1=f(index+1,target-(-nums[index]),nums);
    int ch2=f(index+1,target-(nums[index]),nums);

return ch1+ch2;
}
    int findTargetSumWays(vector<int>& nums, int target) {
     return f(0,target,nums);   
    }
};