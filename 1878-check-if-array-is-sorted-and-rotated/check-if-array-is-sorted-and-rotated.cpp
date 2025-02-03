class Solution {
public:
    bool check(vector<int>& nums) {
        int rot = 0;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(temp[i]==nums[i]) flag++;
        }
        if(flag==nums.size()) return true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                rot++;
            }
            if (nums[0] < nums[nums.size() - 1])
                rot++;
        }
        return rot <= 1;
    }
};