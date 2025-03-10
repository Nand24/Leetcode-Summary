class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0; int n=intervals.size();
        int newstart=newInterval[0];
        int newend=newInterval[1];

                // left part
        while(i<n && newstart> intervals[i][1])
        {
            res.push_back(intervals[i]);
            i++;
        }


        //collision started
int newo=newInterval[0];
int newe=newInterval[1];
       while(i<n && newend>=intervals[i][0])
       {
           newo=min(newo,intervals[i][0]);
           newe=max(newe,intervals[i][1]);
        i++;
       }
       res.push_back({newo,newe});
       while(i<n)
       {
        res.push_back(intervals[i]);
        i++;
       }
return res;
    }
};