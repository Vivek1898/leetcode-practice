class Solution {
public:
    int memo(int i , vector<int>& v ,vector<int>& dp ){
        if( i >= v.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int robAndMove =  v[i] + memo(i+2,v,dp);
        int move = memo(i+1,v,dp);
        
        return dp[i] = max(robAndMove,move);

    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,-1);
        return memo(0,nums,dp);
        
    }
};