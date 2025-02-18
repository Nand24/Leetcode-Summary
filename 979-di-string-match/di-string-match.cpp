class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res(s.size());
        int j = 0;
        int k = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                res[i] = j;
                j++;
            }
            if (s[i] == 'D') {
                res[i] = k;
                k--;
            }
        }
        if(s[s.size()-1]=='D') res.push_back(k);
        else res.push_back(j);
        return res;
    }
};