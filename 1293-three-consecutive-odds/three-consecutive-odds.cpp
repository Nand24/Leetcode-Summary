class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool res=false;
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%2!=0)
            {
                if(i+1<arr.size() && i+2<arr.size())
                {
                    if(arr[i+1]%2!=0 && arr[i+2]%2!=0) res=true;
                }
            }
        }
        return res;
    }
};