class Solution {
private:
    bool isSet(int x, int bit) { return x & (1 << bit); }
    void setbit(int& x, int bit) { x = x | (1 << bit); }

    void unset(int& x, int bit) { x = x & ~(1 << bit); }

public:
    string tobinary(int x) {
        string res;
        while (x != 1) {
            if (x % 2 == 0) {
                res += '0';
            } else
                res += '1';
            x = x / 2;
        }
        res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
    int getbitcnt(string str) {
        int setbitcnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1') {
                setbitcnt++;
            }
        }
        return setbitcnt;
    }

    int minimizeXor(int num1, int num2) {
        string str1 = tobinary(num1);
        string str2 = tobinary(num2);

        int res = num1;
        int targetbitcnt = getbitcnt(str2);
        int setbitcnt = getbitcnt(str1); // bits of result
        int currentbit = 0;
        while (setbitcnt < targetbitcnt) {
            if (!isSet(res, currentbit)) {
                setbit(res, currentbit);
                setbitcnt++;
            }
            currentbit++;
        }
        while (setbitcnt > targetbitcnt) {
            if (isSet(res, currentbit)) {
                unset(res, currentbit);
                setbitcnt--;
            }
            currentbit++;
        }
        return res;
    }
};