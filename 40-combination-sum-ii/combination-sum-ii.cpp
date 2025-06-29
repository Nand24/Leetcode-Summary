class Solution {
public:
void f(int index,vector<int>&temp,vector<int>& candidates,vector<vector<int>>&ans,int target,int n)
{
    //if(index==n) return;
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    if(index<n &&target<candidates[index]) return;
    
    for(int i=index;i<n;i++)
    {       if(i>index && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            f(i+1,temp,candidates,ans,target-candidates[i],n);
            temp.pop_back();
    }
    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> tmep;
         f(0,tmep,candidates,ans,target,n);
         return ans;
    }
};