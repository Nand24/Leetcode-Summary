class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tencount=0;
        int fivecnt=0;
      for(int i=0;i<bills.size();i++)
      {
        if(bills[i]==10)
        {
            tencount++;
            if(fivecnt>0)
            fivecnt--;
            else return false;
        }
        if(bills[i]==20)
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
        if(bills[i]==5) fivecnt++;
        }
      
       return true;
      }
    
};