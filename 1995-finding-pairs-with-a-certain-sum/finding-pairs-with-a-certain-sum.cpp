class FindSumPairs {
public:
vector<int> nums1 ;
vector<int> nums2;
map<int,int> mpp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
         this->nums1=nums1;
         this->nums2=nums2;
         for(int i=0;i<nums2.size();i++)
         {
            mpp[nums2[i]]++;
         }

    }
    
    void add(int index, int val) {

        int temp=nums2[index];
        nums2[index]+=val;
       mpp[temp]--;
       mpp[nums2[index]]++;
    }
    
    int count(int tot) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=0;
       
        for(int i=0;i<n1;i++) if(mpp.find(tot-nums1[i])!=mpp.end()) ans+=mpp[tot-nums1[i]];
       return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */