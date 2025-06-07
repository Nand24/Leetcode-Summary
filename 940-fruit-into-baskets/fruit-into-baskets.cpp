class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=INT_MIN; unordered_map<int,int>mpp;
        int start=0;
        int end=0;
        while(end<fruits.size())
        {        mpp[fruits[end]]++;
                while(mpp.size()>2){
                    mpp[fruits[start]]--;
                    if(mpp[fruits[start]]==0) mpp.erase(fruits[start]);
                    start++;
                    
                }
                maxlen=max(maxlen,end-start+1);
                end++;
        }
        return maxlen;
    }
};