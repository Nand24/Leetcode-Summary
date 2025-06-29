class Solution {
public:
void f(int index,int k,int target,vector<int>&temp,vector<int>&nums,vector<vector<int>>&ans)
{
    //if(index<9 && nums[index]>target) return;
    if(k==0  && target!=0) return;
    if(k<0) return;
    if(target==0 && k==0){
         ans.push_back(temp);
         return;
        }
        for(int i=index;i<9;i++)
        {
            
            temp.push_back(nums[i]);
            f(i+1,k-1,target-nums[i],temp,nums,ans);
            temp.pop_back();
        }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,k,n,temp,nums,ans);
        return ans;
    }
};