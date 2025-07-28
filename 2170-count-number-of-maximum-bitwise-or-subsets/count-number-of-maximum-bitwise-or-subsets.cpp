class Solution {
public:
    int maxOR = 0, count = 0;

    void dfs(int index, int currOR, vector<int>& nums) {
        if (index == nums.size()) {
            if (currOR == maxOR) {
                count++;
            }
            return;
        }

      
        dfs(index + 1, currOR | nums[index], nums);
        
     
        dfs(index + 1, currOR, nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
     
        for (int num : nums) {
            maxOR |= num;
        }

        dfs(0, 0, nums);
        return count;
    }
};
