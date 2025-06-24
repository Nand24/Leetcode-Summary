class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        vector<int> jv;
            for(int j=0;j<nums.size();j++)
            { 
                if(nums[j]==key)
                {
                    jv.push_back(j);
                }
            }
            for(int i=0;i<nums.size();i++)
            {
                for(int j=0;j<jv.size();j++)
                {
                    if(abs(i-jv[j])<=k) {res.push_back(i); break;}
                }
            }
             return res;
    }
};