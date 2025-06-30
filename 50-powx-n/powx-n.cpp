class Solution {
public:
double f(double x,long long n,double&ans)
{
    if(n==0) return 1;
    if(n%2==0) {
       return ans= f(x*x,n/2,ans);
    }
    if(n%2==1)
    {
        return ans=x*f(x,n-1,ans);
    }
    return ans;
}
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(n>0)
        ans=f(x,nn,ans);
        else 
        ans=f(x,-nn,ans);
        if(n<0) return double(1/ans);
        return ans;
        
    }
};