class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0]; int end=intervals[0][1];
        int i=1;
        while(i<intervals.size())
        {
             // overlap
                   if(intervals[i][0] <= end)
                   {
                    start=min(start,intervals[i][0]);
                    end=max(end,intervals[i][1]);
                   }
               
                   else{
                       res.push_back({start,end});
                    start=intervals[i][0]; end=intervals[i][1];
                  }
                  
                   i++;
        }
        res.push_back({start,end});
        
        return res;
    }
};