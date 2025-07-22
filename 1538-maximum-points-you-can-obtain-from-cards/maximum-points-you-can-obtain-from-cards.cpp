class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=k-1;
        int r=cardPoints.size()-1;
        int lsum=0;
        for(int i=0;i<=l;i++) lsum+=cardPoints[i];
        int rsum=0;
        int sum=lsum+rsum;
        while(l>=0)
        {
           lsum-=cardPoints[l];
           rsum+=cardPoints[r];
           sum=max(sum,lsum+rsum);
           l--;
           r--;
        }
        return sum;
    }
};