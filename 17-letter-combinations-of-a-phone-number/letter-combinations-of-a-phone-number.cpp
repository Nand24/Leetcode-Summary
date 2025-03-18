class Solution {
public:
void func(int i,vector<string>&characters,string temp,vector<string>&ans,int n )
{
    if(temp.size()==n)
    {
        ans.push_back(temp);
        return;
    }
    for(int j=0;j<characters[i].size();j++)
    {
        temp.push_back(characters[i][j]);
        func(i+1,characters,temp,ans,n);
        temp.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
       vector<string> characters(digits.size()," ");
       vector<string> str(10," ");
       str[2]="abc";
       str[3]="def";
       str[4]="ghi";
       str[5]="jkl";
       str[6]="mno";
       str[7]="pqrs";
       str[8]="tuv";
       str[9]="wxyz";
      for(int i=0;i<digits.size();i++)
      {
        characters[i]=(str[digits[i]-'0']);
      }
      int n=digits.size();
     string temp;
     vector<string> ans;
     if(digits.size()==0) return ans;
     func(0,characters,temp,ans,n);
return ans;
    }
};  