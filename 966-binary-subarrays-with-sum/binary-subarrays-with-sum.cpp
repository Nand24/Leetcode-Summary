class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        int k=goal;
       unordered_map<int,int> prefixmap;
       prefixmap[0]=1;
       for(int i=0;i<nums.size();i++)
       {
         sum+=nums[i];
      //'   if(sum==k) cnt++;
         if(prefixmap.find(sum-k)!=prefixmap.end()) cnt+=prefixmap[sum-k];
         prefixmap[sum]++;;
       }
        return cnt;
    }
};