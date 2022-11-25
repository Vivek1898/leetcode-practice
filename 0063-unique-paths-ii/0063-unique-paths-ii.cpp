class Solution {
public:
    vector<vector<int>> dp;
    int fun(int x, int y, vector<vector<int>>& grid){
        if(grid[x][y]==1) return 0;
        if(x==0 && y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = 0;
        if(x>0) ans += fun(x-1, y, grid);
        if(y>0) ans += fun(x, y-1, grid);
        return dp[x][y] = ans;
    }
    int uniquePathsWithObstaclesMemo(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();   
        dp.resize(m, vector<int>(n, -1));
        return fun(m-1, n-1, grid);
    }
     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return 0;
        int m = grid.size(), n = grid[0].size();   
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                dp[i][j] = 0;
                if(grid[i][j]==1) continue;
                if(i>0) dp[i][j] += dp[i-1][j];
                if(j>0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};