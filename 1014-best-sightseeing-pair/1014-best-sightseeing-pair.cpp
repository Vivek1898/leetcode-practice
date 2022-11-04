class Solution {
public:
    // Calculate max value of
    // max(v[i]+i) + max(v[i]-i)
    
    int maxScoreSightseeingPair(vector<int>& v) {
        int cmax=v[0]+0;
        int ans=-1;
        for(int i=1;i<v.size();i++){
            ans=max(ans,cmax+v[i]-i);
            cmax=max(cmax,v[i]+i);
        }
        return ans;
    }
};