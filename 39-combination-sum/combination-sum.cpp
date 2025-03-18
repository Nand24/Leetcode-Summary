class Solution {
public:
void func(int index,vector<vector<int>>&ans,vector<int>&temp,vector<int>&candidates,int target)
{
    int sum=0;
    for(int i=0;i<temp.size();i++)
    {
        sum+=temp[i];
    }
    if(sum==target)
    {
        ans.push_back(temp);
        return;
    }
    if(sum>target) return;
    for(int i=index;i<candidates.size();i++)
    {
            temp.push_back(candidates[i]);
            func(i,ans,temp,candidates,target);
            temp.pop_back();
    }

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0,ans,temp,candidates,target);
        return ans;
    }
};