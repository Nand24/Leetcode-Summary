class Solution {
public:
int sum(int n)
{
    int s=0;
    int t=0;
    while(n>0)
    {
        t=n%10;
        s+=t;
        n=n/10;
    }
    return s;
}
    int countLargestGroup(int n) {
        vector<int> freq(37,0);
        for(int i=1;i<=n;i++)
        {
               freq[sum(i)]++;
        }
        int maxfreq=*max_element(freq.begin(),freq.end());
        int cnt=0;
        for(int i=1;i<37;i++)
        {
            if(freq[i]==maxfreq) cnt++;
        }
        return cnt;
    }
};