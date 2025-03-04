class Solution {
public:
    int candy(vector<int>& ratings) {
        int i=1;
        int n=ratings.size();
        int sum=1;
        while(i<n)
        {
             // constant curve ie no inc/dec curve
            if(ratings[i]==ratings[i-1]){
                sum++; i++; continue;
            }
            // slope is increasing
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++; sum+=peak; i++;
            }
            // slope is decreasing
            int down=1;
            while(i<n &&ratings[i]<ratings[i-1])
            {
                 sum+=down; i++; down++;
            }
            // check if crest is more than trough
            if(down> peak) sum+=down-peak;
        }
        return sum;
    }
};