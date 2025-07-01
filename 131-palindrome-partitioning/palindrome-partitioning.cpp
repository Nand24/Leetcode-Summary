class Solution {
public:
bool isPalindrome(string&str)
{
    string tmp=str;
    reverse(tmp.begin(),tmp.end());
    if(tmp==str) return true;
    else return false;
}
void f(int idx,string&s,vector<vector<string>>&ans,vector<string>&path,int n)
{
    
    if(idx==n)
    {
         ans.push_back(path);
        return;
    }
    for(int i=idx;i<s.size();i++)
    {
        string sub=s.substr(idx,i-idx+1); 
         if(isPalindrome(sub)){
            path.push_back(sub);
         f(i+1,s,ans,path,n);
         path.pop_back();
         }

    }
   return;
}

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.size();
        string tmp;
        vector<string> path;
        f(0,s,ans,path,n);
        return ans;
    }
};