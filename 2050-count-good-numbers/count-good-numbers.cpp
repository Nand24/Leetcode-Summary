class Solution {
public:
  const int MOD = 1e9 + 7;
long long f(long long x,long long n,long long&ans)
{
    if(n==0) return 1;
    if(n%2==0) {
       return ans= f((x%MOD)*(x%MOD),n/2,ans);
    }
    if(n%2==1)
    {
        return ans=(x%MOD)*(f(x,n-1,ans)%MOD);
    }
    return ans;
}
    int countGoodNumbers(long long n) {
      
        long long ans = 1;    
        long long even=0;
        long long odd=0;
        if(n%2==0){
               even=n/2; odd=even;
        }
        else{
                 odd=n/2;
                 even=n/2 +1;
        }
           long long ans1;
        ans1= f(5,even,ans1);
        long long ans2;
        ans2= f(4,odd,ans2);
         return ((ans1%MOD)*(ans2%MOD))%MOD;
    }
};
