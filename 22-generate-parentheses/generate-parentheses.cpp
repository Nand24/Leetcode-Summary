class Solution {
public:
void printF(int index,string&temp,vector<string>&ans,int opencnt,int closecnt,int n)
{
    if(index==2*n && opencnt==closecnt)
    {
        ans.push_back(temp);
        return;
    }
    if(opencnt<=n && opencnt>=closecnt)
    {
 
         // take '('
         temp[index]='('; 
          printF(index+1,temp,ans,opencnt+1,closecnt,n);
          // take')'
          temp[index]=')';
          printF(index+1,temp,ans,opencnt,closecnt+1,n);


    } 
    else
    {
        return;
    }

}
    vector<string> generateParenthesis(int n) {
        string temp(2*n,' ');
        int opencnt=0; int closecnt=0;
        vector<string> ans;
        printF(0,temp,ans,0,0,n);
        return ans;
    }
};