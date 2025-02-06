class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];

                if (mp.find(product) != mp.end()) {
                    cnt += mp[product];
                }

                mp[product]++;
            }
        }
        return cnt * 8;
    }
};
