class Solution {
public:
int f(int ind,int target,vector<int>&coins,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(target%coins[ind]==0) return target/coins[ind];
        else return 1e9;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int not_take=0+f(ind-1,target,coins,dp);
    int take=INT_MAX;
    if(coins[ind]<=target)
    {
        take=1+f(ind,target-coins[ind],coins,dp);
    }
    return dp[ind][target]=min(take,not_take);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector(amount+1,-1));
        if( f(n-1,amount,coins,dp)==1e9) return -1;
        else return f(n-1,amount,coins,dp);
    }
};