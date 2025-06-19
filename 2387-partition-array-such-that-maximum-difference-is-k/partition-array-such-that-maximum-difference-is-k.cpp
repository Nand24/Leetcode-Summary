class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int max=nums[0];
        int min=nums[0];
        int i=0;
        while(i<nums.size()){
             if(nums[i]-min<=k)
             {
                   max=nums[i];
             }
             else
             {
                ans++;
                min=nums[i];
                max=nums[i];
             }
             i++;
        }
        return ans+1;
    }
};