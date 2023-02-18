class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
           vector<vector<int>>ans;
     //   if(intervals.size()==0) return ans;
    intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<int>pre = intervals[0];
    
        for(auto i:intervals){
            
            if(i[0]<=pre[1]){
                pre[1]=max(i[1],pre[1]);
            }else{
                
                ans.push_back(pre);
                pre=i;
                
            }
        }
        
        
        ans.push_back(pre);
        
        return ans;
    }
};