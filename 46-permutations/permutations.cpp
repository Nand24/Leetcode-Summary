class Solution {
public:
void func(int index,vector<vector<int>>&ans, vector<int>&temp,vector<int>&nums,vector<int>&hash)
{
    if(index==nums.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(hash[i]==0)
        {
        temp.push_back(nums[i]);
        hash[i]=1;
        func(index+1,ans,temp,nums,hash);
        hash[i]=0;
        temp.pop_back();
        }
    }
    return;
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> hash(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            hash[i]=0;
        }
vector<vector<int>> ans;
vector<int> temp;
func(0,ans,temp,nums,hash);
return ans;

    }
};