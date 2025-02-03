class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 0;
        int icnt = 1;
        int dcnt = 1;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > nums[i - 1]) {
                int j = i;
                int cnt = 1;
                while (j < nums.size() && nums[j] > nums[j - 1]) {
                    cnt++;
                    j++;
                }
                icnt = max(icnt, cnt);
            }

            if (nums[i] < nums[i - 1]) {
                int j = i;
                int cnt = 1;
                while (j < nums.size() && nums[j] < nums[j - 1]) {
                    cnt++;
                    j++;
                }
                dcnt = max(dcnt, cnt);
            }
        }
        return max(dcnt, icnt);
    }
};