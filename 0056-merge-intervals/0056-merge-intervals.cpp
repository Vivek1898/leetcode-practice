class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            
        vector<vector<int>> mergedIntervals;
        if(intervals.size()==0)
            return mergedIntervals;
        
        sort(intervals.begin(),intervals.end());// sort
        vector<int> pre_interval = intervals[0];
        // 0 is starting point
        //1 is ending point
        
        //treating as 1d
        for(auto interval:intervals)
        {
            if(interval[0]<=pre_interval[1])// means there is overlapping of intervals
            {
                pre_interval[1]=max(interval[1],pre_interval[1]); // need to check which has max ending points hence we will make ending point of pre_interval to max
            }
            else
            { // if there is no overlapping
                mergedIntervals.push_back(pre_interval); // simplely push pre-interval to mergedintervals vector
                pre_interval=interval;
            }     
        }
        
        mergedIntervals.push_back(pre_interval);
        return mergedIntervals;
    }
};