class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>m;
        for(auto it:edges){
            m[it[0]]++;
              m[it[1]]++;
        }
        
        int maxi=INT_MIN;
        for(auto it: m){
            if(it.second>maxi){
                maxi=it.first;
            }
        }
        
        return maxi;
    }
};