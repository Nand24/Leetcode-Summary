class Solution {
public:
void func(int index,vector<vector<int>>&ans,vector<int>&temp,vector<int>&candidates,int target)
{
  int sum=0;
  if(index==candidates.size())
  {
    return;
  }
  for(int i=0;i<temp.size();i++)
  {
    sum+=temp[i];
  }
  if(sum>target) return;
  if(sum==target){
    ans.push_back(temp);
    return;
  }
  // pick
  temp.push_back(candidates[index]);
  func(index,ans,temp,candidates,target);
  

  //not pick
  temp.pop_back();
  func(index+1,ans,temp,candidates,target);


}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0,ans,temp,candidates,target);
        return ans;
    }
};