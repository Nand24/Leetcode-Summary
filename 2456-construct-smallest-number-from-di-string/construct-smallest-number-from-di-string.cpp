class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        stack<int> st;
        for(int i=0;i<=pattern.size();i++)
        {
            st.push(i+1);
            if(i==pattern.size()|| pattern[i]=='I')
            {
                while(!st.empty())
                {
                    char c=st.top() +'0';
                    res+=c;
                    st.pop();
                }
            }
        }
        return res;
}
};