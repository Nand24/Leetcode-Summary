class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
   if(!(nums[0] + nums[1]> nums[2] &&nums[0] + nums[2]> nums[1]&& nums[1] + nums[2]> nums[0]))
   {
      return "none";
   }
int i=0;
int cnt=0;
while(i!=nums.size())
{
    i++;
    if(nums[i]==nums[i-1])
    {
        cnt++;
    }
}
if(cnt==0)
{
    return "scalene";
}
if(cnt==2)
{
    return "equilateral";
}
else
{
    return "isosceles";
}
    }
};