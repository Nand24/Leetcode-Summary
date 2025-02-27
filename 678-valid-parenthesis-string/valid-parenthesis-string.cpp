class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for(int i=0;i<s.size();i++)
         {
            if(s[i]=='(')
            {
                  min++; max++;
            }
            else if(s[i]==')')
            {
                min--;
                max--;
            }
            else if(s[i]=='*')
            {
              if(min-1 >=0)
              {
                min=min-1;
                max=max+1;
              }
              else 
              {
                min=min+0;
                max=max+1;
              }   
            }
            if(min<0) min=0;
            if(max<0) return false;
         }
         return (min==0);
    }
};