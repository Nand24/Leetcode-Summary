class Solution {
public:
    int beautySum(string s) {
         int ans=0;
    for (int i = 0; i < s.size(); i++) {
            map<char, int> freq; 
                for (int j = i; j < s.size(); j++) {
                freq[s[j]]++; 
                int max_freq = INT_MIN, min_freq = INT_MAX;
                for (auto it : freq) {
                    max_freq = max(max_freq, it.second);
                    min_freq = min(min_freq, it.second);
                }

                ans += (max_freq - min_freq); 
            }
        }

     return ans;
    }
};