class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> mp;  
        int n = nums.size();
        long long totalPairs = (long long)n * (n - 1) / 2; 
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;  
            goodPairs += mp[diff]; 
            mp[diff]++; 
        }

        return totalPairs - goodPairs; 
    }
};
