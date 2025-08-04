class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int> mpp;
        int l=0;
        int r=0;
        int maxlen=INT_MIN;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()<=2){
                   maxlen=max(maxlen,r-l+1);
               
            }
            else{
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            r++;
        }
        return maxlen;
    }
};