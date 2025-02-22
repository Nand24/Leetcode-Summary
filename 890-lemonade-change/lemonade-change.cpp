class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tencount=0;
        int fivecnt=0;
      for(auto it:bills)
      {
        if(it==5) fivecnt++;
        if(it==10)
        {
            tencount++;
            if(fivecnt>0)
            fivecnt--;
            else return false;
        }
        if(it==20)
        {
            if(tencount>0 && fivecnt>0){
            fivecnt--;
            tencount--;
            }
           else if(tencount<=0 && fivecnt>=3)
            {
                fivecnt-=3;
            }
            else
            return false;
        }
    
      }   return true;
    }
    
};