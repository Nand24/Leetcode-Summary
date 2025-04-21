class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
           int currprofit=prices[i]-mini;
           mini=min(mini,prices[i]);
           maxprofit=max(maxprofit,currprofit);
        }
        return maxprofit;
    }
};