class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int maxindex=0;
        for(int i=0;i<nums.size();i++)
        {  
           if(maxindex<i) return false;
            maxindex=max(maxindex,i+nums[i]);

        }
 return true;
    }
};