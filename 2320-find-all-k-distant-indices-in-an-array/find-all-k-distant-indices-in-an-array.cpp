class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
            for(int i=0;i<nums.size();i++)
            {   
                    for(int j=0;j<nums.size();j++)
                    {
                        if((abs(i-j)<=k) && nums[j]==key){ res.push_back(i); break;}
                    }
                
            }
            sort(res.begin(),res.end()); return res;
    }
};