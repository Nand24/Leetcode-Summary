class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
    int sum=-1;
    sum=derived[0];
         for(int i=1;i<derived.size();i++)
         {

              sum=sum^derived[i];
         }
         if(sum==0)
         {
            return true;
         }
         else
         return false;


    }
};