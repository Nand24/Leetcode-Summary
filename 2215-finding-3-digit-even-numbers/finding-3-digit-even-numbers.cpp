class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        map<int, int> mp;
        for (int d : digits) {
            mp[d]++;
        }

        for (int i = 100; i <= 999; i++) {
            if (i % 2 == 0) {
                int x0 = i % 10;
                int x1 = (i / 10) % 10;
                int x2 = i / 100;

                
                map<int, int> temp = mp;
                if (temp[x0]-- > 0 && temp[x1]-- > 0 && temp[x2]-- > 0) {
                    res.push_back(i);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
