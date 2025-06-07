class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=INT_MIN; unordered_map<int,int>mpp;
        int start=0;
        int end=0;
        while(end<fruits.size())
        {        mpp[fruits[end]]++;
                if(mpp.size()<=2){
                     maxlen=max(maxlen,end-start+1);
                }
                else{
                    mpp[fruits[start]]--;
                    if(mpp[fruits[start]]==0) mpp.erase(fruits[start]);
                    start++;
                }
                end++;
        }
        return maxlen;
    }
};