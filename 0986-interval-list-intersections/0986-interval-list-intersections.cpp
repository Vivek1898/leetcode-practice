class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        
        vector<vector<int>>ans;
        
        int i=0;
        int j=0;
        
        while(i<f.size() and j<s.size()){
            
            int st=max(f[i][0],s[j][0]);
            int et=min(f[i][1],s[j][1]);
            
            if(st<=et) ans.push_back({st,et});
            
            if(f[i][1]<=s[j][1]) i++;
            else j++;
            
        }
        
        return ans;
        
    }
};