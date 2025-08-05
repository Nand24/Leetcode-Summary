class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        long long ans=0;
        unordered_map<int,int> mpp;
       // for(int i=0;i<nums.size();i++) mpp[nums[i]]++;
       long long paircnt=0;
       int n=nums.size();
        while(l<nums.size()){
           
           while(paircnt <k && r<nums.size() ){
                 
                  mpp[nums[r]]++;
                  if(mpp[nums[r]]>1) paircnt+=mpp[nums[r]]-1;
                  r++;

           }
            if(paircnt>=k){
                    ans+=n-r+1;
                 }
          
         
           if(mpp[nums[l]]>1)
            paircnt-=mpp[nums[l]]-1;

              mpp[nums[l]]--;
           l++;
        }
        return ans;
    }
};