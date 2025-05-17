class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int z=0,o=0,t=0;

        for(auto i:nums)
        if(i==0)
        z++;
        else if(i==1)
        o++;
        else if(i==2)
        t++;

        int c=0;
        for(int i=0;i<z;i++)
        nums[c++]=0;

        
        for(int i=0;i<o;i++)
        nums[c++]=1;

        
        for(int i=0;i<t;i++)
        nums[c++]=2;
    }
};