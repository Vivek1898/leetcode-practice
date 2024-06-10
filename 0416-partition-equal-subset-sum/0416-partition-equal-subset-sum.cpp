class Solution {
public:
    int solve(int i , int t , vector<int>&a , vector<vector<int>>&dp){
        if(t==0) return true;
        if(i==0) return a[0] == t;

        if(dp[i][t] != -1) return dp[i][t];
        
        int n = solve(i-1,t,a,dp);
        bool y = false;

        if(a[i]<=t) y = solve(i-1,t - a[i],a,dp);

        return dp[i][t] = y || n;
        
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ;
        for(auto it:nums) sum+=it;
       if (sum & 1) {
            return false;
        }else {
            int half = sum/2;
            vector<vector<int>>dp(n,vector<int>(half+1,-1));
            return solve(n-1,half,nums,dp);
        }
        
    }
};