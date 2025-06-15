class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;
        char x;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != '9') {
                x = str1[i];
                for (int j = i; j < str1.size(); j++) {
                    if (str1[j] == x)
                        str1[j] = '9';
                }
                break;
            }
        }
        int a = stoi(str1);
        char y;
        char z;
        if (str2[0] == '1') {

            for (int i = 1; i < str2.size(); i++) {
                if (str2[i] !='1' && str2[i]!='0') {
                    z = str2[i];
                    for (int j = i; j < str2.size(); j++) {
                        if (str2[j] == z)
                            str2[j] = '0';
                    }
                    break;
                }
            }
        } 
        else {
            for (int i = 0; i < str2.size(); i++) {
                if (str2[i] != '1') {
                    y = str2[i];
                    for (int j = i; j < str2.size(); j++) {
                        if (str2[j] == y)
                            str2[j] = '1';
                    }
                    break;
                }
            }
        }
        int b = stoi(str2);
        cout << a << endl << b;
        return abs(b - a);
    }
};