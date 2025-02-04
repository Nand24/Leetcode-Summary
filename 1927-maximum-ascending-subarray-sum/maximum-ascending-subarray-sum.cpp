class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int maxsum = 0;
        int currentsum = nums[0];
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > nums[i - 1]) {

                currentsum += nums[i];
                maxsum = max(maxsum, currentsum);
            } else {
                maxsum = max(maxsum, currentsum);
                currentsum = nums[i];
            }
        }

        return maxsum;
    }
};