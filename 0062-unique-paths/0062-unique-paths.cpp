class Solution {
public:
    
    int count(int i, int j, vector<vector<int> > &dp) {
     // base case
        if(i==0 and j==0) return 1;
        //Boundary 
        if(i<0  or j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=count(i,j-1,dp);
        int up=count (i-1,j,dp);
        
        return dp[i][j]=left+up;
        
    }
    int uniquePathsMemo(int m, int n) {
     vector<vector<int> > dp(m,vector<int>(n,-1));
        return count(m-1,n-1,dp);
        
    }
    
         int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];   // sum of unique paths ending at adjacent top and left cells
        return dp[m-1][n-1];         // return unique paths ending at cell (m-1, n-1)
    }
};