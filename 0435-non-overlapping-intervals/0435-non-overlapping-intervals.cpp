class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int et=intervals[0][1];
      //  cout<<et<<endl;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<et) {
                ans++;
                et=min(intervals[i][1],et);
            }else{
                et=intervals[i][1];
            }
        }
        return ans;
    }
};