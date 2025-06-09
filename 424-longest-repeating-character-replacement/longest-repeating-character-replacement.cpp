class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0;
        int end=0;
        int maxlen=INT_MIN;
        vector<int> hash(26,0);
        int maxfreq=0;
        while(end<s.size())
        {
                 hash[s[end]-'A']++;
                 maxfreq=max(maxfreq,hash[s[end]-'A']);
                 int len=end-start+1;
                 if((len-maxfreq)>k)
                 {
                        hash[s[start]-'A']--;
                        start++;
                 }else
                 maxlen=max(maxlen,len);
                 end++;
        }
        return maxlen;
    }
};