class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int flag = 0;
        vector<int> tmp;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i])
                continue;
            else
                flag++;
        }
        if (flag == 0)
            return true;
        else if (flag == 2) {
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i]) {
                    tmp.push_back(i);
                }
            }
            char x, y;
            x = s2[tmp[0]];
            y = s2[tmp[1]];
            s2[tmp[0]] = y;
            s2[tmp[1]] =x;
            if(s1==s2) return true;
            else return false;
        }
        else return false;
    }
};