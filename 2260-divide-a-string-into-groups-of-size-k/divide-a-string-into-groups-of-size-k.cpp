class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for(int i=0;i<s.size();i+=k)
        {
            string part=s.substr(i,k);
            if(part.size()<k)
            {
                  part.append(k-part.size(),fill);
            }
            
            res.push_back(part);
        }
    return res;
    }
};