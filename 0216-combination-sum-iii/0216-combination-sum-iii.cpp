class Solution {
public:
    void helper( int idx,  vector<vector<int>>&ans,  vector<int>&curr,int n,int k){
        if(n==0 and curr.size()==k){
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx;i<=9;i++){
            curr.push_back(i);
           helper(i+1,ans,curr,n-i,k);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(1,ans,curr,n,k);
        return ans;
    }
};