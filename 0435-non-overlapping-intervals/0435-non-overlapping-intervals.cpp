class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        
        //0-start
        // 1-end
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int curr=intervals[0][1];
        cout<<curr<<endl;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<curr) {
                ans++;
                curr=min(intervals[i][1],curr);
            }else{
                curr=intervals[i][1];
            }
        }
        return ans;
    }
};