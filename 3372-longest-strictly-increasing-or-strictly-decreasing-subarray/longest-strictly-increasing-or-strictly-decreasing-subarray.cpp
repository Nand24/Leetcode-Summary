class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1;
        int icnt = 1;
        int dcnt=1;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > nums[i - 1]) {
                icnt++;
                maxi = max(maxi, icnt);
            }
            else
            {
                icnt=1;
            }
            if (nums[i] < nums[i - 1]) {
                dcnt++;

                maxi = max(maxi, dcnt);
            } else {
                dcnt = 1;
            }
        }
       return maxi;
    }
};