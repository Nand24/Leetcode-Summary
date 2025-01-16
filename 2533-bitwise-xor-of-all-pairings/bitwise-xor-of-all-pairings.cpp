class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0) {
            return 0;
        }
        int ans = 0;
        if (nums1.size() % 2 == 0 && nums2.size() % 2 != 0) {

            ans = nums1[0] ^ nums1[1];
            for (int i = 2; i < nums1.size(); i++) {
                ans = ans ^ nums1[i];
            }
        }
         if (nums1.size() % 2 != 0 && nums2.size() % 2 == 0) {

            ans = nums2[0] ^ nums2[1];
            for (int i = 2; i < nums2.size(); i++) {
                ans = ans ^ nums2[i];
            }
        }

         if (nums1.size() % 2 != 0 && nums2.size() % 2 != 0) {

            for(int i=0;i<(nums1.size());i++)
            {
                
                ans=nums1[i]^ans;
            }

             for(int i=0;i<(nums2.size());i++)
            {
                
                ans=nums2[i]^ans;
            }
        }

        return ans;
    }
};