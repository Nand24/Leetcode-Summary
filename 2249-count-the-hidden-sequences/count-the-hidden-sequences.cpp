class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
     int cnt=0;   
long long currsum=0;
long long minval=LLONG_MAX;
long long maxval=LLONG_MIN;
  for(int i=0;i<differences.size();i++)
  {
          currsum+=differences[i];
         minval=min(minval,currsum);
         maxval=max(maxval,currsum);

  }
  for(int i=lower;i<=upper;i++)
  {
    if(i+maxval<=upper && i+minval>=lower) cnt++;
  }
  return cnt;

    
    }
};