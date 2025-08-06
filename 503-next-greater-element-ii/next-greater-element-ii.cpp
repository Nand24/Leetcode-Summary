class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
       vector<int> nums2=nums;
        for(int j=0;j<n;j++){
            nums2.push_back(nums[j]);
        }
        stack<int> st;
        vector<int> nge(2*n);
        for(int j=nums2.size()-1;j>=0;j--){
            
           while(!st.empty() && st.top()<=nums2[j]){
            st.pop();
           }
            if(st.empty()){
                 
                  nge[j]=-1;
            } 
            else{
                
                nge[j]=st.top();
            }
            st.push(nums2[j]);
        }
       
        vector<int> res(n);
        for(int i=0;i<n;i++) res[i]=nge[i];
        return res;
    }
};