class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=0;j<m;j++){
                mini=min(mini,matrix[i][j]);
            }
            st.insert(mini);
        }
        for(int i=0;i<m;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                maxi=max(maxi,matrix[j][i]);
            }
            if(st.count(maxi)){
                return {maxi};
            }
        }
        return {};
    }
};