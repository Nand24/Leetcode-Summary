class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int l=0;
        int r=0;
        int len=0;
        long long maxsum=0;
        long long sum=0;
        while(r<nums.size()){
              
              len=r-l+1;
              mpp[nums[r]]++;
              sum+=nums[r];
             // cout<<sum<<endl;
              if(len==k ){
                if(mpp.size()==k){
                maxsum=max(maxsum,sum);
                cout<<maxsum<<endl;
                 sum-=nums[l];
                 mpp[nums[l]]--;
                 if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                 l++;
                }
                else{
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                sum-=nums[l];
                l++;
                }
            }
            
              r++;
            //  cout<<sum;
       
        }
        return maxsum;
    }
};